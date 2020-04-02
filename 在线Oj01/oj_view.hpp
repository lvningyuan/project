#pragma once 
#include "ctemplate/template.h"
#include <string>
#include <vector>
#include "oj_model.hpp"

class OjView
{
  public:
    //渲染Htlm页面，并且返还给调用者
   static void DrawAllQuestions(std::string* html,std:: vector <Questions>& ques)//html页面
    {
      //1 获取数据字典---->把拿到的试题数据按一定的顺序保存到内存
      ctemplate::TemplateDictionary dict("all_questions");//建立数据字典
   for(const auto& que: ques)
   {
      //增加片段 必须同html片段描述符一致
      ctemplate::TemplateDictionary* section_dict = dict.AddSectionDictionary("question");
      section_dict->SetValue("id", que.id_);
      section_dict->SetValue("name", que.name_);
      section_dict->SetValue("star", que.star_);
   }      
      //2  获取模板类指针
      //3 渲染， 拿着的模板类的指针 将数据自店内的数据更新到html页面中保存
    
          
    
    }

};
