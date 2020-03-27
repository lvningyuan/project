#include "iostream"
#include <stdio.h>

using namespace std;

int main()
{
  FILE* fOut = fopen("6.txt","wb");
  FILE* fIn = fopen("6.txt","rb");

  int d=10;
  while(d)
  {
    fputc('c',  fOut);
    d--;
  }

  cout<<"fOut: "<<ftell(fOut)<<endl;
  fseek(fIn, 0, SEEK_END);
  cout<<"1 fIn: " <<ftell(fIn)<<endl;

  //测fflush 
  fflush(stdout);
  fseek(fIn, 0, SEEK_END);
  cout<<"fflush fIn: " <<ftell(fIn)<<endl;

  fclose(fOut);
  fseek(fIn, 0, SEEK_END);
  cout<<"2 fIn: " <<ftell(fIn)<<endl;

  char p[22] ={0};

  fread(p,1, 20, fIn);
  cout<<*p<<endl;

  fclose(fIn);
  return 0;
}
