#include <stdio.h>
#include <cstdlib>
#include "FileCompressHuff.h"
#include <assert.h>
#include "HuffManTree.hpp"
#include <algorithm>
#include <unistd.h>


//字符信息构造函数
FileCompressHuff::FileCompressHuff()
{
  _fileInfo.resize(256);
  for(int i=0; i<256; ++i)
  {
    _fileInfo[i]._ch = i;//初始化字符
    _fileInfo[i]._count =0;
  }
}


// 正式压缩 --其实可以分为多个函数
void FileCompressHuff::CompressFile(const string& path)
{
  //1 统计原文件中每个字符出现的次数
  FILE* fIn = fopen(path.c_str(),"rb");//不仅文本文件 ，也得二进制文件
  assert(fIn);

  char*  pReadBuff = new char[1024];
  while(true)
  {
    ssize_t rdsize =  fread(pReadBuff, sizeof(char), 1024, fIn);
    if(rdsize == 0)
      break;

    for(int i=0; i<rdsize; ++i)
    {
      _fileInfo[pReadBuff[i]]._count ++;//给读到的字符数量+1
    }
  }


  //2  以这些次数 作为权值 ，构建Huffman树
  HuffmanTree<CharInfo> t (_fileInfo, CharInfo(0));//CharInfo 为默认值，即无效结点 初始化列表count=0 这里给不给赋值都行

  //3 根据Huffman树 获取每个字符的编码
  FileCompressHuff:: GenerateHuffManCode(t.GetRoot());  //GetRoot获取根结点指针   GenerateHuffManCode 逐个结点开始获取编码


  //4 用获取到的字符编码改写源文件 ,二进制写压缩文件，后期才能正常解压缩
  FILE* fOut = fopen("2.txt","wb");
  assert(fOut);

  WriteHead(fOut, path);
  //sleep(1);
 
  char ch =0;  //用于给文件中存放，一次存放一个字节 即8位
  int bitCount =0;//计数比特位够不够1字节
  fseek(fIn, 0, SEEK_SET);//从文件头读
  while(true)//一直读，直到读完
  {
    ssize_t  rdsize  = fread(pReadBuff, 1, 1024,fIn);
    if(rdsize == 0)//读完了
    {
      break;
    }

    //根据读到的编码对读取到的内容进行重写
    for(int i =0; i<rdsize; ++i)//遍历每个字节
    {
      string strCode = _fileInfo[ pReadBuff[i]].strCode; //每个字节中对应的哈夫曼编码   string串
      for(size_t j=0; j<strCode.size(); ++j)//获取编码的每个字符   （类似于每一位）
      {
        ch <<=1; //每次左移一位 
        if('1' == strCode[j])                       //为1时需要置1，为0 时不用处理，直接移位
          ch |= 1; //将Huffman编码放入一个字符中，以后每次放字符

        bitCount++;


        if(bitCount == 8)//编码写满一字节了，就进行保存
        {
          fputc(ch,fOut);
          cout<<"NO, i'm  first"<<endl;
          bitCount =0;
          ch = 0;
        }

      }
    }   
  }
  //最后一次ch中可能不够8个比特位，所以可能不会写入，因此我们应该循环外再写一个fputc；
  if(bitCount !=0 )
  {
    ch<<= (8-bitCount);
    fputc(ch,fOut);
  }

  delete [] pReadBuff;
  fclose(fIn);
  fclose(fOut);
}


//压缩方面函数   获取哈夫曼编码
void FileCompressHuff::GenerateHuffManCode(HuffmanTreeNode <CharInfo>* pRoot)
{
  //1 先递归走到叶子位置
  if(nullptr == pRoot)
    return ;

  string strCode;
  GenerateHuffManCode(pRoot->_pLeft);
  GenerateHuffManCode(pRoot->_pRight);

  //2 从叶子开始反向求路径
  if(pRoot->_pLeft == nullptr && pRoot->_pRight ==nullptr)//走到叶子节点了
  {
    HuffmanTreeNode<CharInfo>* cur =pRoot;
    HuffmanTreeNode<CharInfo>* parent = cur->_pParent;
    while(cur->_pParent != nullptr)//父节点不空
    {

      if(cur == parent ->_pLeft)
      {
        strCode += '0';
      }
      else //右孩子 + ‘1’
      {
        strCode +='1';
      }
      cur =parent;  
      parent = parent->_pParent;

    }
    reverse(strCode.begin(), strCode.end()); 
    _fileInfo[pRoot->_weight._ch].strCode = strCode;//保存编码
  }
}

//为解压缩做准备，保存文件后缀等信息
void FileCompressHuff:: WriteHead(FILE* fOut,const string& fileName)//保存文件的后缀   
{
  assert(fOut);

  //写文件后缀 
  std::string strHead;
  strHead += GetFilePostFix(fileName);
  strHead += '\n';
// `` fwrite(&strHead, 1, strHead.size(), fOut);
 
  //写字符及出现次数
  size_t lineCount =0; //字符行数
  string strChCount;
 
  
  for(int i=0; i<256; ++i )
  {
    char szValue[32] ={0};//接收出现次数 转为字符串
    CharInfo&  charInfo = _fileInfo[i];//纯粹为了写起来方便
    if(charInfo._count)
    {
      lineCount++;

      strChCount += charInfo._ch;//获取字符
      strChCount += ':';
      sprintf(szValue,"%d", (int)charInfo._count);//转化每个字符出现次数为字符串  
      string tmp = szValue;
      strChCount += tmp;
      strChCount += '\n';
    }
  }

  char szValue[32] ={0};//接收出现次数 转为字符串
  sprintf(szValue,"%d", (int)lineCount);//转化行数为字符串 

  string tmp = szValue;
  strHead += tmp;
  strHead += '\n';

  strHead += strChCount;
  fwrite(strHead.c_str(), 1, strHead.size(), fOut);
  cout<<"写入压缩数据 :"<<strHead<<endl;
  cout<<"i'm first"<<endl;
}


//为解压缩准备文件后缀
string FileCompressHuff::GetFilePostFix(const string& FileName)
{
  return  FileName.substr(FileName.rfind('.')); //反向找 '.'  截取后缀 
}



//  解压缩用获取每一行的信息
void FileCompressHuff::ReadLine(FILE* fIn,  string& fileInfo)
{
#if 0
  assert(fIn);
  char* getLine  = new char[1024];//怎么销毁呀
  if(!feof(fIn))
  {
    cout<<"fIn :"<<ftell(fIn)<<endl;
    fgets(getLine,10, fIn);

    fileInfo = to_string(*getLine);
    cout<<"getLine size :"<<fileInfo.size()<<endl;
  }
#endif 
#if 1

    while(!feof(fIn))
    {
      char  ch =fgetc(fIn);
      if(ch == '\n')
         break;
     
      cout<<"fin  :"<<ftell(fIn)<<endl;
      fileInfo += ch; 
    }
#endif
}



//解压缩
void FileCompressHuff::UnCompressFile(const string& path)
{

  FILE* fIn = fopen(path.c_str(), "rb");
  assert(fIn);

  //获取后缀 
  string strFilePostFix;
  ReadLine(fIn, strFilePostFix);
  cout<<"后缀为"<<strFilePostFix<<endl;
  cout<<"fIn 2  :"<<ftell(fIn)<<endl;


  //字符信息总行数
  string StrCount;//字符串的行数 
  ReadLine(fIn, StrCount);
  cout<<"fIn 3  :"<<ftell(fIn)<<endl;
 
  
  int lineCount = atoi(StrCount.c_str());
  cout<<"line  count is "<<lineCount<<endl;

  //获取字符信息
  for(int i =0; i<lineCount; ++i)
  {
    string strchCount;//字符的数量
    ReadLine(fIn, strchCount);
    cout<<"fIn  4  :"<<ftell(fIn)<<endl;
  
    
    if(strchCount.empty())//读了个空行
    {
      strchCount += '\n';
      ReadLine(fIn,strchCount);
    }

    // 字符出现的次数   存储形式 A:1          +2跳过钱两个非数字字符
    _fileInfo[(unsigned char)strchCount[0]]._count  =atoi(strchCount.c_str()+2 );//防止出现汉字等，字符的ASCII码变成负数
  }


  // 可还原Huffman树了
  HuffmanTree<CharInfo> t;
  CharInfo a(0);
  t.CreateHuffManTree(_fileInfo ,a);

  // 读取压缩数据，一个个解压缩
  unsigned char readBuff [1024] = {0};
  FILE* fOut = fopen("3.txt", "wb"); 
  HuffmanTreeNode<CharInfo>* pCur = t.GetRoot();//恢复字符时用
  size_t fileSize = t.GetRoot()->_weight._count;//  获取文件总字节大小检测解压缩最后一个字节有效比特位够没够 ，防止多解压缩了
  size_t unCount =0; 
 
  while(true)
  {

    size_t rdsize = fread(readBuff, 1, 1024, fIn);
    cout<<"fIn  5  :"<<ftell(fIn)<<endl;
    if(rdsize == 0)
      break;

    else//读取了rdsize 
    {
      for(size_t i =0; i < rdsize; ++i)//每个字节
      {
        for(int j =0; j<8; ++j)//每个比特位
        {
          if( readBuff[i]   & 0x80 ) //该位为1
          {
            pCur = pCur->_pRight;
          }
          else 
          {
            pCur = pCur ->_pLeft;
          }

          readBuff[i] <<= 1; 
          if(pCur->_pLeft == nullptr && pCur->_pRight == nullptr)
          {
            unCount++; //统计解压了几个字节
            fputc(pCur->_weight._ch, fOut);

            if(unCount == fileSize)
              break;

            pCur = t.GetRoot();
          }
        }
      }
    }
  }
  fclose(fIn);
  fclose(fOut);
}



