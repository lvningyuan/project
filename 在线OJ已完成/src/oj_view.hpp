#pragma once 
#include <ctemplate/template.h>
#include "oj_model.hpp"
#include <cassert>
#include <string>
#include <vector>


class OjView
{
  public:
    //ctemplate 命名空间下有一个Template模板类，类中有一个建立模板数据字典的方法和渲染的方法
    //所谓渲染其实就是填充


   // 1  渲染展示题目页面 
   
   
   //渲染html题库页面，通过html传出
    static void ExpandAllQuestions(std::string* html,  std::vector<Questions>& ques)//html页面
    {
      //<1> 创建模板数据字典---->保存所有题目id + path + name + star

      ctemplate::TemplateDictionary dict("all_questions");//建立数据字典，参数没啥用，便于调试
      for(const auto& que: ques)
      {
        //增加片段字典 必须同html片段描述符一致
        //填充字典每个片段
        ctemplate::TemplateDictionary* section_dict = dict.AddSectionDictionary("questions");
        section_dict->SetValue("id", que.id_);
        section_dict->SetValue("name", que.name_);
        section_dict->SetValue("star", que.star_);
      }      
      
      //<2>  获取模板类地址
      ctemplate::Template* t1 = ctemplate::Template::GetTemplate("./template/all_questions.html",ctemplate::DO_NOT_STRIP);
        assert(t1); 
      
      //<3>渲染，（填充）   拿着的模板类的指针 将数据字典内的数据更新到html页面中保存
      t1->Expand(html, &dict);    
      cout<<"html size ："<<html->size()<<endl;
      cout<<html<<endl;
    }




    //2  渲染(填充)一个题目模板
    static void ExpandOneQuestion(const Questions& ques, std::string& desc,
                                                  std::string& header, std::string* html)   //单个题目哦 
    {
      ctemplate::TemplateDictionary dict("question");//参数是数据字典的名字
        dict.SetValue("id", ques.id_);
        dict.SetValue("name", ques.name_);
        dict.SetValue("star", ques.star_);
        dict.SetValue("desc", desc);
        dict.SetValue("header", header);
        
        //获取模板类的指针，因为不知到具体模板类对象，所以无法通过对象.调用渲染函数。
        ctemplate::Template* tpl = ctemplate::Template::GetTemplate("./template/question.html", ctemplate::DO_NOT_STRIP); //渲染这个html文件页面，逐行逐句渲染
        
        if(tpl == nullptr)
          {
            cout<<"Questions tp1 Failed"<<std::endl;
            return ;
          }
        tpl->Expand(html, &dict);//底层还是递归渲染的
    }



//3  渲染原因模板

    static  void ExpandReason(const std::string& errorno, const std::string reason,  const std::string& stdout_reason, std::string* html)
    {
        ctemplate::TemplateDictionary dict("question");//参数随便起,参数是为了调试用，和代码逻辑无关
        dict.SetValue("errorno", errorno);
        dict.SetValue("reason", reason);
        dict.SetValue("stdout", stdout_reason);
        
        ctemplate::Template* tp1 = ctemplate::Template::GetTemplate("./template/reason.html",ctemplate::DO_NOT_STRIP); //渲染这个html文件页面，逐行逐句渲染
          if(tp1 == nullptr)
          {
            cout<<" ExpandReason tp1 Failed"<<std::endl;
            return ;
          }

        tp1->Expand(html, &dict);
    }
};
