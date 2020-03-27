#pragma once 
#include "LZHashTable.h"
#include <string>
using namespace std;


const USH MIN_LOOKAHEAD =MIN_MATCH + MAX_MATCH + 1;//能保证本次长度够（最大匹配长度）258 + 1 ，还得保证下次也可以进行
const USH MAX_DIST = WSIZE - MIN_LOOKAHEAD;//MAX_DIST为减去WSIZE - LOOKAHEAD 的长度  即查找缓冲区（有效）的最大长度 

class LZ77
{

  public:
    LZ77();
    ~LZ77();

    //压缩文件的方法
    void CompressFile(const string& strFilePath);

    void UnCompressFile(const string& strFilePath);

    string GetPostFix(string fileName);

    void MergeFile(FILE* fOUT,ULL fileSize);//fileName 用于获取后缀

    void FillWindow(FILE* fIn, size_t& lookAHead, USH& start);
  private:
    USH LongestMatch(USH matchHead, USH& MatchDist, USH _start);//带出最长匹配长度和  最大匹配距离
   
    void WriteFlag(FILE* fOutF, UCH& chFlag, UCH& bitCount, bool isCharOrLen);//传出标记（状态的）字节 
                      //注意  这里几个变量都得传引用， 我在这里翻了大跟头 

  private:
    UCH* _pWin;//待压缩数据的缓冲区地址  .h只是声明
    LZHashTable _ht;//底层需要哈希表来进行存放
};
