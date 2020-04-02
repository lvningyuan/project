#include <string.h>
#include <string>
#include "httplib.h"
#include "oj_model.hpp"
//#include "oj_log.hpp"

int main()
{
  using namespace httplib;//只在当前模块生效

  Server svr;
  OjModel ojmodel;
  //【var】 ：值传递，lambda内部操作不会影响外边
  //【this】: 值传递this指针
  //层次匹配 + 回调函数
  //获取试题信息
  svr.Get("/all_questions", [&ojmodel](const Request& req, Response& resp){
      //获取题目列表
      std::vector<Questions> ques;
      ojmodel.GetAllQuestions(&ques);
      if(ques.size() != 0)
        printf("hahaha\n");
      
        //获取题干信息
      char buf[10240] ={'\0'};
      snprintf(buf, sizeof(buf)-1, "<html>%s.%s %s</html>",ques[0].id_.c_str(),
                         ques[0].name_.c_str(), ques[0].star_.c_str());
      std::string html;
      html.assign(buf,strlen(buf));
      
      //用模板技术填充HTML页面
      resp.set_content(html, "text/html; charset=UTF-8");
      });           

  svr.listen("0.0.0.0", 19999);//监听所有ip

  return 0;
}
