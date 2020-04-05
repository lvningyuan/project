#pragma once 
#include "oj_log.hpp"
#include "tools.cpp"
#include <json/json.h>
#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/resource.h>


//编译运行信息
enum ErrorNo
{
  OK =0,  //正常
  COMPILE_ERROR,//编译出错
  RUN_ERROR,//运行 出错
  PRAM_ERROR,//代码错误
  INTER_ERROR//内部出错
};


//编译类
class Compiler
{ 
  public:
    //浏览器提交过来的说句可能不同    
    //code ="xxx"  或 code ="xxx" &stdin"xxx"   code +tail.cpp
    static void CompileAndRun(Json::Value Req, Json::Value* Resp)
    {
      //编译运行期间 ，保存相关信息，
    
      
      
      
      if (Req["code"].empty()) 
      {
        (*Resp)["errorno"] = PRAM_ERROR;
        (*Resp)["reason"] = "Pram error"; 
        LOG(ERROR,"Request Is Empty!")<<std::endl;
        return;
      }

      //将代码写到文件中
      std::string code =Req["code"].asString();
 
      //为防止多用户答题    创建一个 tmp时间戳.cpp   文件名约定格式统一
      std::string tmp_filename = WriteTmpFile(code); 

      if(tmp_filename == "")
      {
        (*Resp)["errorno"] = INTER_ERROR;
        (*Resp)["reason"] = "Create file failed";
        LOG(ERROR, "WriteTmpFile Failed");
        return;
      }
      //3 编译 
      if (!Compile(tmp_filename))
      {
        (*Resp)["errorno"] = COMPILE_ERROR;
        std::string reason;
        FileOper::ReadDataFromFile(StderrPath(tmp_filename), &reason);
        (*Resp)["reson"] = reason; 
        LOG(ERROR, "Compile Error !")<<std::endl;
        return ;
      }

      //4  运行
      int  sig = Run(tmp_filename);//获取退出信息
      if(Run(tmp_filename) != 0)
      {
        (*Resp)["errorno"] = RUN_ERROR;
        (*Resp)["reason"] = "pram exit by sig:" + std::to_string(sig);
        LOG(ERROR, "Run Error")<<std::endl;
        return;
      }

      //5  回应浏览器
      (*Resp)["errorno"]  = "OK" ; 
      (*Resp)["reason"] = "Compile and run is okey!";
      //标准输出
      std::string stdout_reason;
      FileOper::ReadDataFromFile(StdoutPath(tmp_filename), &stdout_reason);
      (*Resp)["stdout"] = stdout_reason;
      //标准错误
      std::string stderr_reason;
      FileOper::ReadDataFromFile(StderrPath(tmp_filename), &stderr_reason);

      //6清理掉临时文件
      Clean(tmp_filename); 
      return;
    }


  private:
    static bool Compile(const std::string& filename)
    {
      //1 构造编译命令
      const int commandcount =20;//set command len
      char  buf[commandcount][50] ={{0}}; //init command 集合
      char* Command[commandcount] ={NULL}; //设置结尾
      for(int i=0; i < commandcount; ++i)
      {
        Command[i] = buf[i];
      }

      snprintf(Command[1], 49, "%s", SrcPath(filename).c_str());
      snprintf(Command[2], 49, "%s", "-o");
      snprintf(Command[3], 49, "%s", ExePath(filename).c_str());
      snprintf(Command[4], 49, "%s", "-std=c++11");
      snprintf(Command[5], 49, "%s", "-D");//定义一个宏
      snprintf(Command[6], 49, "%s", "CompileOnline");
      Command[7] =NULL;    
      //2 fork 子进程执行，父进程等待  fork成功返回新进程的id  ，getpid获取当前进程id  getppid父进程id
      int pid = fork();
      if(pid < 0)
      {
        LOG(ERROR, "fork failed\n");
        return false;
      }
      else if(pid ==0)
      {
        //将编译错误保存在特定文件
        int fd = open(ErrorPath(filename).c_str(), O_CREAT |O_RDWR, 0664);//创建Error的文件
        //重定向
        if(fd < 0)
          LOG(ERROR, "failed open Error file :")<<ErrorPath(filename).c_str()<<std::endl;
        dup2(fd, 2);
        execvp(Command[0], Command);
        exit(0);  
      }
      else
      {
        //father进程 程序替换
        waitpid(pid, NULL, 0);   
      }
      //3 验证是否产生了可执行程序
      struct stat st;
      int n = stat(ExePath(filename).c_str(), &st);
      if(n != 0)
      {
        LOG(ERROR, "Create Exe file failed! file path is")<<ExePath(filename)<<std::endl;
        return false;
      }
      return true;
    }

  private: 
    static int Run(std::string& filename)
    {
      //1  创建子进程
      pid_t pid = fork();
      if(pid < 0)
      {
        LOG(ERROR, "Run Failed, Exe file is invalued, file path is")<<ExePath(filename)<<std::endl;
        return -1;
      }
      else if(pid == 0) 
      {
        //child
        //2  目标： 进程程序替换 
        // 执行限制  ：1  时间  2  内存 
        alarm(2);  
        struct rlimit rlt;
        rlt.rlim_cur = 1024;//最小内存 软限制
        rlt.rlim_max = 1024 * 10000;//z最大内存
        setrlimit(RLIMIT_AS,&rlt);
        
        //准备文件 将标准输出重定向到文件中
        int stdout_fd  = open(StdoutPath(filename).c_str(), O_CREAT |O_RDWR);
        if(stdout_fd < 0)
        {
          LOG(ERROR, "open stdout file failed! file name is ")<<StdoutPath(filename)<<std::endl;
          return -1;
        }
        dup2(stdout_fd, 1);

        //准备文件 ，将标准错误重定向
        int stderr_fd = open(StderrPath(filename).c_str(), O_CREAT |O_RDWR);
        if(stderr_fd < 0)
        {
          LOG(ERROR, "open stdout file failed! file name is ")<<StderrPath(filename)<<std::endl;
          return -1;
        }
        dup2(stderr_fd, 2);
        execl(ExePath(filename).c_str(), ExePath(filename).c_str(), NULL);
        exit(0);
      }
      else
      {
        // father等待
        int Status = -1;  //位图机制 ，高八位: 退出信息  第九位 coredump标志位 低七位:退出信号
        waitpid (pid, &Status, 0);
        return Status & 0x7f;  //返回子进程退出的信息      
      }      
    }

  private: 
    //清理服务端垃圾文件   服务端保存这些没啥暖用,   unlink 自己去找，找到就清理掉了
    static void Clean(std::string& filename)
    {
      unlink(SrcPath(filename).c_str());
      unlink(ExePath(filename).c_str());
      unlink(StderrPath(filename).c_str());
      unlink(StdoutPath(filename).c_str());
      unlink(ErrorPath(filename).c_str());
    }


  private:
    //写时间戳文件
    static std::string WriteTmpFile(const std::string& code)
    { 
      //1 组织文件名格式统一
      std::string tmp_filename="tmp" + std::to_string(LogTime::GetTimeStamp());
      //2 保存数据
      int ret = UrlUtil::WiterDataToFile(SrcPath(tmp_filename), code);
      if(ret !=0 )
      {
        LOG(ERROR,"WriteDataToFile Failed!\n");
        return "";
      }
      return tmp_filename;
    } 

    static std::string SrcPath(const std::string& filename)
    {
      return "./tmp_files" + filename + ".cpp";
    }

    static std::string StdoutPath(const std::string& filename)
    {
      return "./tmp_files" + filename + ".stdout";
    }

    static std::string StderrPath(const std::string& filename)
    {
      return "./tmp_files" + filename + ".stderr";
    }

    static std::string ExePath(const std::string& filename)
    {
      return "./tmp_files" + filename + ".excutable";
    }

    static std::string ErrorPath(const std::string& filename)
    {
      return "./tmp_files" + filename + ".err";
    }
};
