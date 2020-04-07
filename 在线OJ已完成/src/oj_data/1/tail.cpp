#ifndef  CompileOnline


//下面这些打印是为了编译用例有相关提示，实际上在线oj根本看不到这些
#include "header.cpp"
#endif


void Test1()
{
  bool ret = Solution().isPalindrome("101");//匿名对象调用
  if(ret == true)
    cout<<"Test 1 is Right !"<<endl;
  else 
    cout<<"Test 1 is Wrong !"<<endl;
}

void Test2()
{
  bool ret = Solution().isPalindrome("10");//匿名对象调用
  if(ret == false)
    cout<<"Test 2 is Right !"<<endl;
  else 
    cout<<"Test 2 is Wrong !"<<endl;
}


int main()
{
  Test1();
  Test2();
  return 0;
}
