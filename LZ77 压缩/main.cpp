#include "LZ77.h"
#include <iostream>

using namespace std;
int main()
{
  LZ77 lz;
  lz.CompressFile("1.txt");
  cout<<"压缩完成"<<endl;
  lz.UnCompressFile("2.lzp");
  cout<<"解压缩完成"<<endl;
  return 0;
}
