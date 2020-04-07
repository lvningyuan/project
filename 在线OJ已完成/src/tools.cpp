#pragma  once 
#include <iostream>
#include <vector>
#include <unordered_map>
#include <boost/algorithm/string.hpp>  //boost库函数
#include <fstream>
#include <oj_log.hpp>



//切割工具类： 将题目信息切割出来
class StringTools
{
  public:
    //切个对象 + 切割方式 + 存放地址
    static void Split(const std::string& input, const std::string& split_char ,std::vector<std::string>*  output)
    {
      boost::split(*output, input, boost::is_any_of(split_char), boost::token_compress_off);
    }
};



//文件操作类
class FileOper
{
  public:
    //1 从文件中读取数据，保存在content内部带出
      static int ReadDataFromFile(const std::string& filename, std::string* content)
    {
      std::ifstream file(filename.c_str());//读方式
      if(!file.is_open())
      {
        LOG(ERROR, "Open File failed, filename is ")<<filename<<std::endl;
        return -1;
      }

      std::string line;//读取到line中暂时保存
      while(std::getline(file, line))
      {
        *content += line + '\n';
      }
      file.close();
      return 0;
    }
    
      
    //2  写将Data数据入文件保存
      static  int WiterDataToFile(const std::string& filename, const std::string& Data)               
    {
      std::ofstream file(filename.c_str());//写文件的文件流指针
      if(!file.is_open())
      {
        LOG(ERROR, "Failed open File");
        return -1;
      }

      file.write(Data.data(),Data.size());
      file.close();
      return 0;
    }
};




//解码类
class UrlUtil
{
  public:
    //解析Body    
     static void PraseBody(const std::string& body, std::unordered_map<std::string,std::string>* pram)
    {
         // body格式:  name=xxx&stdin=xxx
          std::vector<std::string> tokens;//得到name=xxx  和 stdin==xxx
          StringTools::Split(body, "&", &tokens);
          for(const auto& token : tokens)
          { 
            //name =xxx
            std::vector<std::string> vec;
            StringTools::Split(token, "=", &vec);
            if(vec.size() != 2)
            {
              continue;   //本项有问题，跳过
            }
            //Url解码 vec[i] :value 
           (*pram)[vec[0]] = UrlDecode(vec[1]);//将answer存在map中
          }
    }


    //具体解码方法
    static unsigned char ToHex(unsigned char x) 
   { 
     return  x > 9 ? x + 55 : x + 48; 
   }

   static unsigned char FromHex(unsigned char x) 
   { 
     unsigned char y;
     if (x >= 'A' && x <= 'Z') y = x - 'A' + 10;
     else if (x >= 'a' && x <= 'z') y = x - 'a' + 10;
     else if (x >= '0' && x <= '9') y = x - '0';
     else assert(0);
     return y;
   }

   static std::string UrlEncode(const std::string& str)
   {
     std::string strTemp = "";
     size_t length = str.length();
     for (size_t i = 0; i < length; i++)
     {
       if (isalnum((unsigned char)str[i]) || 
           (str[i] == '-') ||
           (str[i] == '_') || 
           (str[i] == '.') || 
           (str[i] == '~'))
         strTemp += str[i];
       else if (str[i] == ' ')
         strTemp += "+";
       else
       {
         strTemp += '%';
         strTemp += ToHex((unsigned char)str[i] >> 4);
         strTemp += ToHex((unsigned char)str[i] % 16);
       }
     }
     return strTemp;
   }
      
   static std::string UrlDecode(const std::string& str)
   {
     std::string strTemp = "";
     size_t length = str.length();
     for (size_t i = 0; i < length; i++)
     {
       if (str[i] == '+') strTemp += ' ';
       else if (str[i] == '%')
       {
         assert(i + 2 < length);
         unsigned char high = FromHex((unsigned char)str[++i]);
         unsigned char low = FromHex((unsigned char)str[++i]);
         strTemp += high*16 + low;
       }       
       else strTemp += str[i];
     }
     return strTemp;
   }
};
