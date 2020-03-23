#pragma once 
#include "HuffManTree.hpp"
#include <string>
#include <vector>



using namespace std;

struct CharInfo
{

  char _ch;
  size_t _count;//出现次数
  string strCode;//对应的编码
 
  CharInfo(size_t count = 0 )
   :_count(count)
  {}

  //HuffMan构建新二叉树的时候形成新二叉树时，   权值进行相加了，
  CharInfo  operator+ (const CharInfo b)
  {
    return CharInfo (_count + b._count); //返回一个CharInfo无名对象  构建新二叉树时，不能直接加对象，所以必须重载+
                              //在返回时 ，返回值类型并不是int的， 而是传进来的W类型的，因此要莫返回W类型，要莫构建一个CharInfo无名对象
  }
  bool operator > (const CharInfo& b)
  {
    return _count > b._count;//向堆里插入时 需要比较，但两个结构体不能直接比较  所以需要重载 >
  }

  bool operator ==(const CharInfo& b)
  {
    return  _count == b._count;
  }
};





class FileCompressHuff
{

  //typedef   HuffmanTreeNode<CharInfo>  HuffmanTreeNode;
  public:
   
    FileCompressHuff();
    
    void CompressFile(const string& FileName);

    void UnCompressFile(const string & FileName);
    
    void WriteHead(FILE* fOut,const string& filePostFix);//保存文件的后缀
    
    void GenerateHuffManCode(HuffmanTreeNode <CharInfo>*  pRoot);
    
  private:
    //获取huffman编码的函数
    //varvoid   GenerateHuffManCode(HuffmanTreeNode <CharInfo>* pRoot);
    
    string GetFilePostFix(const string& FileName);
    
    void   ReadLine(FILE* fIn, string& fileInfo);
  
  private:
  
    vector<CharInfo> _fileInfo;//字符个数肯定不会超过256

};

