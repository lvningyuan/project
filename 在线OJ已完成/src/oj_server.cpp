#pragma once
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include "oj_model.hpp"
#include "oj_view.hpp"
#include "httplib.h"
#include "oj_log.hpp"
#include "compile.hpp"
#include <unordered_map>

int main()
{
  using namespace httplib;//只在当前模块生效

  Server svr;
  OjModel ojmodel;
  //层次匹配 + 处理函数(回调)
  //获取试题信息
#if 1


  //  Get(模式，处理函数)模式可以理解为哪层目录, 只有浏览器传具体路径匹配时才会执行handler函数，这里的handler函数我们用lambda表达式来代替 
  svr.Get("/questions", [&ojmodel](const Request& req, Response& resp){
      //获取题目列表
      std::vector<Questions> ques;
      ojmodel.GetAllQuestions(&ques);
      printf("进入Get\n");
#if 0  
      //测试使用：    获取题干信息
      char buf[10240] ={'\0'};
      snprintf(buf, sizeof(buf)-1, "<html>%s.%s %s</html>",ques[0].id_.c_str(), ques[0].name_.c_str(), ques[0].star_.c_str());

      std::string html;
      html.assign(buf,strlen(buf));
      //stringstream ss  
#endif 
#endif
      std::string html;
      //使用模板技术去渲染（填充）html页面
      OjView::ExpandAllQuestions(&html, ques);
      resp.set_content(html, "text/html; charset=UTF-8");
      });         


  //  C++正则表达式， 可以将string 分成多个string，  通过match[]可以获取每个片段
  //  正则表达式来匹配题目  
  //  \b分界
  //  * 匹配任意长度字符/串
  //  \d  匹配一个个位数  \d+可以匹配高位数
  //  \为转义字符,需要源码转义 R"()"
  //  (\d+)  分组应用
#if 1
  svr.Get(R"(/questions/(\d+))", [&ojmodel](const Request& req, Response& resp){
      //question1 
      //1  去试题模块查找对应的具体题目信息
      //   map当中（序号 名称，题目地址，难度）  主要为了查找题目地址
      //   由题目地址获取题目的具体信息
      LOG(INFO,"req.matches")<<req.matches[0]<<":"<<req.matches[1]<<std::endl;//req = name + id 

      //在题目目录下获取单个题目 
      std::string desc;//题目描述信息
      std::string header;//题目头部信息
      std::string id;
      const std::string  tmp_id = req.matches[1].str();
      Questions ques_info;//获取题目信息
      ojmodel.GetOneQues(tmp_id, &desc, &header,&ques_info);

      //3 进行组织渲染html页面，返回给浏览器
      string html;
      OjView::ExpandOneQuestion(ques_info, desc, header, &html);
      resp.set_content(html, "text/html; charset=UTF-8");
  });

#endif 
#if 1
  svr.Post(R"(/questions/(\d+))",[&ojmodel](const Request& req,  Response& resp){    
      
      //目的 ：获取提交内容， 获取code  并对提交内容的正确性给出响应
      
      //注意 1 提交的内容当中有url编码，需要进行解码//http下编码
      
#if 1 
      //底层容器    将解析到有效的数据存放在unordere_map    
      std::unordered_map<std::string, std::string>pram;
      UrlUtil::PraseBody(req.body, &pram);//从req请求中解析出Body
      for(const auto& pr : pram)
      {
        pram["code"] = pr.second;
      }
      
      std::string code;  //合成可编译的源代码 
      ojmodel.SplicingCode(pram["code"], req.matches[1].str(), &code);
      LOG(INFO, "拼接后code")<<code<<std::endl; 
      Json::Value req_json;    // 构造json对象req   请求对象的内容就是完整代码
      req_json["code"] = code; // 完整代码
      Json::Value Resp_json;   // 构造json对象Resp
      
      Compiler::CompileAndRun(req_json, &Resp_json);  //编译并运行，底层进行用例测试

      //3 构造响应浏览器的结果 
      const std::string errorno = Resp_json["errorno"].asString();
      const std::string reason  = Resp_json["reason" ].asString();
      const std::string stdout  = Resp_json["stdout" ].asString();
      
      std::string html;
      OjView::ExpandReason(errorno, reason, stdout, &html); 
#endif
      resp.set_content (html, "text/html;charset=UTF-8");//UTF-8是一种编码格式
  });
#endif 

  LOG(INFO, "listen on 192.168.8.133 : 9999")<<std::endl;
  LOG(INFO, "Server ready")<<std::endl;
  svr.listen("192.168.8.133", 9999);//监听所有ip
  return 0;
}
