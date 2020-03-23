#include "FileCompressHuff.h"

//#include "HuffManTree.hpp"


int main()
{
  FileCompressHuff  fc;
  fc.CompressFile("1.txt");
  cout<<"压缩正常"<<endl;
  fc.UnCompressFile("2.txt");
  cout<<"解压缩正常"<<endl;
  return 0;
}
