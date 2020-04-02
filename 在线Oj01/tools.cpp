#pragma  once 
#include <iostream>
#include <vector>
#include <boost/algorithm/string.hpp>  //boost库函数
//切割工具： 将题目信息切割出来
class StringTools
{

  public:
      //切个对象 + 切割方式 + 存放地址
    static void Split(const std::string& input, const std::string& split_char ,std::vector<std::string>*  output)
    {
      boost::split(*output, input, boost::is_any_of(split_char),boost::token_compress_off);
    }
};

