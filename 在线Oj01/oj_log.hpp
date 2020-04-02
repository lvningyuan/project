#pragma  once 
#include <cstdio>
#include <cstring>
#include <iostream>
#include <sys/time.h>

//当前实现的Log 服务也是在控制台进行输出的
//确定输出格式
//日志内容包括 【时间， 日志等级， 具体处于哪个文件， 行号】+ 具体日志信息 

class LogTime
{
  public:
#if 0
    static  int64_t GetTimeStamp()
    {
      struct timeval tv;

      gettimeofday(&tv, nullptr);  //连个参数 ，一个秒 ，一个毫秒
      return tv.tv_sec; 
    }
#endif


    //我们设置为年月日 时分秒
    static void GetTimeStamp(std:: string* TimeStamp)
    {
      time_t SysTime;
      time(&SysTime); 
      struct tm* st = localtime(&SysTime);//年月日时分秒结构体  
      char buf[30] = {'\0'};
      snprintf(buf, sizeof(buf) - 1, "%04d-%02d-%02d %02d-%02d-%02d", st->tm_year + 1900,
                  st->tm_mon + 1,st->tm_mday, st->tm_hour, st->tm_min, st->tm_sec);//0可以占位02月
      TimeStamp -> assign(buf, strlen(buf)+1);
    }

};


//日志等级 
//INFO  WAFRNING ERROR FATAL  DEBUG  错误等级

const char* Level[] = {
    "INFO",
    "WARNING",
    "ERROR",
    "FATAL",
    "DEBUG",
};

enum LogLevel
{
  INFO =0,
  WARNING,
  ERROR,
  FATAL,
  DEBUG
};


//__FILE__, __LINE__   C语言查看日志信息_
//inline 保证每个地方都能看日志信息
inline void Log(LogLevel lev, const char* file, int line, std::string& Logmsg)
{
    //日志内容包括 【时间， 日志（错误）等级， 具体处于哪个文件， 行号】+ 具体日志信息 
    std::string level_info = Level[lev];
    std::string TimeStamp;
    LogTime::GetTimeStamp(&TimeStamp);
    std::cout<<"["<<TimeStamp<<" "<<level_info<<" "<< file << ":" <<line<<"]"<<Logmsg<<std::endl;
}

#define LOG(lev, msg) Log(__FILE__, __LINE__, msh)








