#pragma  once 
#include "tools.cpp"
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

    OjModel()
    {
      LoadQuestions("./config_oj.cfg");
    }

    //将所有题干都存在ques数组中
    bool GetAllQuestions(std::vector<QUES>* ques)
    {
      //逐一放入ques数组中-->-无序
     for(const auto& kv : model_map_)
     {
       ques->push_back(kv.second);
     }

     //按照题目的id_对题目进行排序
     //sort(begin, end)  Less  默认升序
     //sort(begin ,end, func)
     sort(ques->begin(), ques->end(), [](const QUES& l, const QUES& r){ 
         return std::atoi(l.id_.c_str()) <  std::atoi(r.id_.c_str()); 
         });

     return true;
    }

    

  private:
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
          //1  第一步，切个字符串
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
    
          model_map_[ques.id_] = ques;//将que以id_为key     保存在map底层
        }
        file.close();//关闭文件流
    return true;
    }

  private:
  //选择底层存储试题数据的数据结构  
    std::unordered_map<string, Questions> model_map_;
};
