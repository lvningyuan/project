#pragma  once 
#include <algorithm>
using namespace std;


//试题块
class Solution{
  public:
    bool isPalindrome(int x){

    }
};

#ifndef "CompileOnline"
#include "header.cpp"
#endif
// 1 约定 每一个用例是一个函数
//        每一个用例从标准输出输出一行日志
//        通过 打印【TestName】 Ok
//        不通过 打印【TestName】failed  + 提升日志

void Test1()
{
  bool ret = Solution().isPalindrome(-10);
  if(ret)
  {
    std::cout<<"Test1 Ok"<<std::endl;
    return true;
  }
  else 
  std::cout<<"Test1 Failed input -10, output expected true, actual false"<<std::endl;
}

void Test2()
{
  bool ret = Solution().isPalindrome(121);
  if(ret)
  {
    std::cout<<"Test2 Ok"<<std::endl;
  }
  else 
  std::cout<<"Test2 Failed input 121, output expected true, actual false"<<std::endl;
}
int main()
{
  Test1();
  Test2();
  return 0;
}
