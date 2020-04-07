#pragma  once 
#include "tools.cpp"
#include "oj_log.hpp"
#include <stdio.h>
#include <iostream>
#include <unordered_map>
#include <string>
#include <fstream>
#include <vector>

using namespace std;


//试题相关信息
typedef struct Questions
{    
  std::string id_;
  std::string name_;
  std::string path_;
  std::string star_;//难度
}QUES;


class OjModel
{
  public:

    OjModel()//构造函数直接将所有题目加载到自己的mdoel_map中
    {
      LoadQuestions("./config_oj.cfg");
    }

    //外界通过接口来询问都有什么题目
    bool GetAllQuestions(std::vector<QUES>* ques)
    {
      for(const auto& kv : model_map_)
      {
        ques->push_back(kv.second);
      }

      //传出给做题者看时，可以把题目按照id排个序 
     
      //按照题目的id_对题目进行排序
      //sort(begin, end)  Less  默认升序
      //sort(begin ,end, func)
      sort(ques->begin(), ques->end(), [](const QUES& l, const QUES& r){ 
          return std::atoi(l.id_.c_str()) <  std::atoi(r.id_.c_str()); 
          });

      return true;
    }

    //从文件中加载题目,直到文件为空
    bool LoadQuestions(const string& configFilePath)
    {
      ifstream file(configFilePath.c_str());//写方式打开文件    file 是文件流指针 
      if(!file.is_open())
      {
        return false;
      }

      string line;
      while(std::getline(file, line))  //从文件中获取一行,存在line中
      {
        //1 第一行测试用刘是  单链表
        //1  第一步，切割字符串
        std::vector<std::string> vec;
        StringTools::Split(line, " ", &vec);//切割哪一行, 用什么字符切割
        if(vec.size() != 4)// 题目信息有问题  
          continue;//跳过本次

        //2  第二步，将切割结果存在unordered_map中
        Questions ques;
        ques.id_    = vec[0];
        ques.name_  = vec[1];
        ques.path_  = vec[2];
        ques.star_  = vec[3];

        model_map_[ques.id_] = ques;//将que以id_为key     保存在model_map_底层
      }
      file.close();//关闭文件流
      return true;
    }


    //由id获取题目所有信息     描述文件 + 头文件  + (id++path+star +niame)
    bool GetOneQues(const std::string& id, std::string* desc, std::string* header, Questions* ques)
    {
      //0 查询题目是否存在
      auto it = model_map_.find(id);
      if(it == model_map_.end())
      {
        LOG(ERROR, "Question Not Found, Qestion id is")<<id<<std::endl;
        return false;
      }

      //1 得到(id + + path +name +  star)
      *ques = it->second;//将题目所有信息（不包含题目描述）传出去


      //2 获取题目描述文件的绝对路径 + 获取 描述文件（传出方式）
      std::string id_path =DescPath(it->second.path_);
      int ret =   FileOper::ReadDataFromFile(id_path, desc);
      if(ret < 0)
      {
        LOG(ERROR,"ReadDataFromFile failed")<<std::endl;
        return false;
      }

      //3 获取头文件绝对路径，并得到头文件
      id_path = HeadPath(it->second.path_);
      ret = FileOper::ReadDataFromFile(id_path, header);
      if(ret == -1)
      {
        return false;
      }

      return true;
    }

    //拼接代码 code 为最终代码
    bool SplicingCode(std::string& usr_code,  const std::string& ques_id, std::string* code)
    {
      // 查看题目是否存在
      auto it =model_map_.find(ques_id);
      if (it == model_map_.end())
      {
        LOG(ERROR ,"queston not found")<<std::endl;
        return false;
      }

      //获得tail信息, usr_code 包含头文件
      std:: string tail_code;
      int ret = FileOper::ReadDataFromFile(TailPath(it->second.path_), &tail_code);
      if(ret < 0)
      {
        LOG(ERROR, "Open tail.cpp failed!")<<std::endl;
        return false;
      }
      
      *code = usr_code + tail_code;
      return true;
    }

  private:

    std::string DescPath(const std::string& ques_path)
    {
      return ques_path + "desc.txt";
    }

    std::string HeadPath(const  std::string& ques_path)
    {
      return ques_path + "header.cpp";
    }

    std::string TailPath(const  std::string& ques_path)
    {
      return ques_path + "tail.cpp";
    }

   private:
      //选择底层存储试题数据的数据结构  
      
      std::unordered_map<string, Questions> model_map_;
    };
