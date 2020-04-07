#ifndef CompileOnline
#include "header.cpp"
#endif 

void Test1()
{
  vector<int>v{1,2,3,1};
  int ret = Solution().rob(v);
  if(ret != 4)
    cout<<"Test1 is wrong"<<endl;
  else 
    cout<<"Test1 is right"<<endl;
}

void Test2()
{
  vector<int>v{2,3,4,3,5};
  int ret = Solution().rob(v);
  if(ret != 11)
    cout<<"Test1 is wrong"<<endl;
  else 
    cout<<"Test1 is right"<<endl;
}

void Test3()
{
  vector<int>v{6,5,4,5,6,7,8};
  int ret = Solution().rob(v);
  if(ret != 24)
    cout<<"Test1 is wrong"<<endl;
  else 
    cout<<"Test1 is right"<<endl;
}

int main()
{
  Test1();
  Test2();
  Test3();
  Test4();
  return 0;
}
