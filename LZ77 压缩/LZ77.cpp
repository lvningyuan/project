#include "LZ77.h"
#include <string.h>
#include <cassert>
#include <iostream>

LZ77::LZ77()
  :_pWin(new UCH[WSIZE * 2])//初始化缓冲区的大小
   ,_ht(WSIZE)         //初始化hash表大小
{}

LZ77::~LZ77() 
{
  delete[] _pWin;
  _pWin = nullptr;
}

//获取文件的后缀
std::string LZ77::GetPostFix(std::string filename)
{
  return filename.substr(filename.rfind("."));
}

//压缩文件
void LZ77 :: CompressFile(const std::string& strFilePath) 
{
  FILE* fIn = fopen(strFilePath.c_str(), "rb");
  if (nullptr == fIn) 
  {
    std::cout << "打开文件失败" << std::endl;
    return;
  }

  //获取文件大小
  fseek(fIn, 0, SEEK_END);//把文件指针移动到文件的末尾
  ULL fileSize = ftell(fIn);//获取当前文件指针到文件开始位置的偏移量

  //1. 如果源文件的大小小于最小匹配长度 MIN_MATCH，则不进行处理,文件太小去进行压缩反而达不到压缩的目的
  if (fileSize <= MIN_MATCH) 
  {          
    //此处是小于3个字符,在common.hpp文件中定义的
    std::cout << "文件太小，不压缩" << std::endl;
    return;
  }

  //从压缩文件中读取一个缓冲区的数据到窗口中
  fseek(fIn, 0, SEEK_SET);//上面把文件指针移动到文件末尾，还得移回来，否则读不到任何数据
  size_t lookAhead = fread(_pWin, 1, 2 * WSIZE, fIn);//表示先行缓冲区中剩余的字节数
  
  USH hashAddr = 0;//记录哈希地址
  //设置起始hashAddr (前两个字符的hash地址)
  for (USH i = 0; i < MIN_MATCH - 1; ++i) 
  {
    _ht.HashFunc(hashAddr,_pWin[i]);
  }

  //压缩
  FILE* fOUT = fopen("2.lzp", "wb");
  assert(fOUT);

  USH start = 0;//查找字符串在缓冲区的地址,随着压缩的不断进行，start不断的在先行缓冲区中增加

  //与查找最长匹配相关的变量
  USH matchHead = 0;       //匹配字符串的头
  USH curMatchLength = 0;  //一次匹配字符串的长度
  USH curMatchDist = 0;    //一次匹配字符串的距离

  //与写标记相关的变量
  UCH chFlag = 0;//代表当前字符是字符还是长度
  UCH bitCount = 0;//代表1个字节已经用了多少字节

  //写标记的文件
  FILE* fOutF = fopen("3.txt", "wb");
  assert(fOutF);

  //lookAhead表示先行缓冲区中剩余字节的个数
  while (lookAhead) 
  {
    //1.将第三个字符插入到哈希表中，因为前两个字符已经插入到哈希表当中，(pWin_[start],pWin_[satrt + 1].pWin_[start + 2])并获取匹配链的头
    _ht.Insert(matchHead, _pWin[start + 2], start, hashAddr);
    
    //因为不只进行一此匹配，每次匹配前都要置为0，防止影响后面的数据
    curMatchLength = 0;
    curMatchDist = 0;

    //2.验证在查找缓冲区中是否找到匹配，如果有匹配，找最长匹配
    //因为在初始化哈希表的时候都设置为0，代表没有任何匹配，如果不为0，代表有匹配
    if (matchHead) 
    {
      //顺着匹配链找最长匹配,最终带出<长度，距离>对
      curMatchLength = LongestMatch(matchHead, curMatchDist, start);
    }

    //3.验证是否找到匹配
    if (curMatchLength < MIN_MATCH) 
    {
      //在查找缓冲区中未找到重复字符串
      //将start位置的字符写入到压缩文件中
      fputc(_pWin[start], fOUT); //写字符

      //写当前原字符对应的标记
      WriteFlag(fOutF, chFlag, bitCount, false);//写标记

      //更新变量
      ++ start;
      lookAhead--;
    }
    else 
    {
      //找到匹配
      //将《长度，距离》对写入压缩文件中
      //写长度
      UCH chLen = curMatchLength - 3;//因为长度是1个字节，其范围本来是[0,255],但是因为是3个一组，所以其范围是[3,258]
      fputc(chLen, fOUT);

      //写距离
      fwrite(&curMatchDist, sizeof(curMatchDist), 1, fOUT);

      //写当前原字符对应的标记
      WriteFlag(fOutF, chFlag, bitCount, true);

      //更新先行缓冲区中剩余的字节数
      lookAhead -= curMatchLength;

      //将已经匹配的字符串按照三个一组将其插入到哈希表中
      --curMatchLength;  //当前字符串已经插入
      ++start;
      while (curMatchLength) 
      {
        _ht.Insert(matchHead, _pWin[start + 2], start, hashAddr);
        --curMatchLength;
        ++start;
      }
    }

    //检测先行缓冲区中剩余字符个数,如果小于最短匹配长度，需要更新缓冲区和哈希表，向缓冲区中重新填充内容，
    if (lookAhead <= MIN_LOOKAHEAD)
      FillWindow(fIn, lookAhead, start);
  }

  //标记位数如果不够八位，因为写标记是8位写一次，最后可能不够8bit，所以要另外判断
  if (bitCount > 0 && bitCount < 8) 
  {
    chFlag <<= (8 - bitCount);
    fputc(chFlag, fOutF);
  }

  fclose(fOutF);

  //把压缩数据文件和标记信息文件合并
  MergeFile("3.txt",fOUT, fileSize);

  //删除标记信息文件
  remove("./3.txt");//删除标记信息文件

  fclose(fIn);
  fclose(fOUT);
}

//向缓冲区中填充数据
void LZ77::FillWindow(FILE* fIn, size_t& lookAhead, USH& start) 
{
  //start压缩已经进行到右窗，先行缓冲区剩余数据不够MIN_LOOKAHEAD
  if (start >= WSIZE) //如果不进行if判断，在进行小文件压缩时还会继续从文件中读取数据，但是文件已经走到末尾
  {
    //1.将右窗中的数据搬移到左窗
    memcpy(_pWin, _pWin + WSIZE, WSIZE);

    //将右窗中的内容清0，防止影响后续数据
    memset(_pWin + WSIZE, 0, WSIZE);

    //更新start，start本来是大于WSIZE，经过1步骤后，start应该在左窗，
    start -= WSIZE;

    //2.更新哈希表
    _ht.upDate();

    //3.向右窗中补充WSIZE个的待压缩数据
    if (!feof(fIn))//判断文件是否走到末尾
      lookAhead += fread(_pWin + WSIZE, 1, WSIZE, fIn);
  }
}

//合并文件
void LZ77::MergeFile(const string& filename,FILE* fOut, ULL fileSize) 
{
  //将压缩数据文件和标记信息文件合并
  //1.读取标记信息文件中内容，然后将结果写入到压缩文件中
  FILE* fInf = fopen("3.txt", "rb");
  size_t flagSize = 0;

  UCH* pReadbuff = new UCH[1024];
  while (true) 
  {
    size_t rdSize = fread(pReadbuff, 1, 1024, fInf);
    if (rdSize == 0)
      break;

    //把标记信息写到压缩数据文件中
    fwrite(pReadbuff, 1, rdSize, fOut);

    //更新数据
    flagSize += rdSize;
  }

  //向压缩数据文件中写标记信息大小，方便解压缩
  fwrite(&flagSize, sizeof(flagSize), 1, fOut);

  //向压缩数据文件中写文件数据大小，方便解压缩
  fwrite(&fileSize, sizeof(fileSize), 1, fOut);

  delete[] pReadbuff;
  fclose(fInf);
}

//chFlag:该字节中的每个比特位是用来区分当前字节是原字符还是长度?
//0:原字符
//1:长度
//bitCount:该字节中的多少个比特位已经被设置
//isCharOrLen:代表该字节是源字符还是长度
void LZ77::WriteFlag(FILE* fOUT, UCH& chFlag, UCH& bitCount, bool isLen)
{
  chFlag <<= 1;
  if (isLen)
    chFlag |= 1;

  bitCount++;
  if (bitCount == 8) 
  {
    //将该标记写入到压缩文件中
    fputc(chFlag, fOUT);
    chFlag = 0;
    bitCount = 0;
  }
}

//匹配：是在查找缓冲区中进行的，查找缓冲区中可能会找到多个匹配
//输出：需要最长匹配
//注意：可能会遇到环状链    解决：设置最大匹配次数
//       匹配是在MAX_DIST范围内进行匹配的，太远的距离则不进行匹配

//在找的过程中，需要将每次找到的匹配结果进行比较，保持最长匹配
USH LZ77::LongestMatch(USH matchHead, USH& MatchDist, USH start) 
{     
  //找最长匹配
  USH curMatchLen = 0;  //一次匹配的长度
  USH maxMatchLen = 0;
  UCH maxMatchCount = 255;   //最大的匹配次数，解决环状链
  USH curMatchStart = 0;     //当前匹配在查找缓冲区中的起始位置

  //在先行缓冲区中查找匹配时，不能太远即不能超过MAX_DIST
  USH limit = start > MAX_DIST ? start - MAX_DIST : 0;

  do {
    //匹配范围
    //先行缓冲区
    UCH* pstart = _pWin + start;
    UCH* pend = pstart + MAX_MATCH;

    //查找缓冲区匹配串的起始
    UCH* pMatchStart = _pWin + matchHead;
    curMatchLen = 0;

    //可以进行本次匹配
    while (pstart < pend && *pstart == *pMatchStart) 
    {
      //更新变量
      ++curMatchLen;
      ++pstart;
      ++pMatchStart;
    }

    //一次匹配结束
    if (curMatchLen > maxMatchLen) 
    {
      maxMatchLen = curMatchLen;
      curMatchStart = matchHead;//一次匹配不一定是最长的匹配，需要更新匹配头
    }

  } while ((matchHead = _ht.GetNext(matchHead)) > limit&&maxMatchCount--);

  MatchDist = start - curMatchStart;
  return maxMatchLen;
}

//解压缩
void LZ77::UnCompressFile(const std::string& strFilePath) 
{
  //打开压缩文件和标记文件
  FILE* fInD = fopen(strFilePath.c_str(), "rb");
  if (nullptr == fInD) 
  {
    std::cout << "压缩文件打开失败" << std::endl;
    return;
  }

  //操作标记数据的文件指针
  FILE* fInF = fopen(strFilePath.c_str(), "rb");
  if (nullptr == fInF) 
  {
    std::cout << "压缩文件打开失败" << std::endl;
    return;
  }

  //获取源文件大小
  ULL fileSize = 0;
  fseek(fInF, 0 - sizeof(fileSize), SEEK_END);
  fread(&fileSize, sizeof(fileSize), 1, fInF);

  //获取标记信息的大小
  size_t flagSize = 0;
  fseek(fInF, 0 - sizeof(fileSize) - sizeof(flagSize), SEEK_END);
  fread(&flagSize, sizeof(flagSize), 1, fInF);

  //将读取标记信息的文件指针移动到保存标记数据的起始位置
  fseek(fInF, 0 - sizeof(flagSize) - sizeof(fileSize) - flagSize, SEEK_END);


  //开始解压缩

  //写解压缩数据
  


  //FILE* ffOut = fopen("5.txt","rb");
  //std::string filestr ;
  //std::cout<<filestr<<std::endl;
  //fread(&filestr,sizeof(filestr),1,ffOut);
  //std::string str = "4.";
  //str += filestr;
  //fclose(ffOut);

  FILE* fOut = fopen("4.txt", "wb");
  assert(fOut);

  FILE* fR = fopen("4.txt", "rb");
  assert(fR);

  UCH bitCount = 0;
  UCH chFlag = 0;
  ULL encodeCount = 0;//标记已经解压缩的数据大小，方便判断解压缩的结束
  while (encodeCount < fileSize) 
  {
    //读取标记
    if (0 == bitCount) 
    {
      //读取一个字节
      chFlag=fgetc(fInF);
      bitCount = 8;
    }

    if (chFlag & 0x80)//当前字节的高位为1 
    {
      //距离长度对
      USH matchLen = fgetc(fInD) + 3;//长度
      USH matchDist = 0;//距离
      fread(&matchDist, sizeof(matchDist), 1, fInD);

      //清空缓冲区 让文件真正写入
      fflush(fOut);

      //更新已经解码的字节数大小
      encodeCount += matchLen;

      //fR：读取前文匹配串中的内容
      UCH ch;
      fseek(fR, 0 - matchDist, SEEK_END);
      while (matchLen) 
      {
        ch = fgetc(fR);
        fputc(ch, fOut);
        --matchLen;

        //在还原长度距离对时，一定要清空缓冲区，否则可能会还原出错

        fflush(fOut);
      }
    }
    else 
    {
      //原字符
      UCH ch = fgetc(fInD);
      fputc(ch, fOut);
      encodeCount += 1;
    }

    chFlag <<= 1;
    bitCount--;
  }

  fclose(fInD);
  fclose(fInF);
  fclose(fOut);
  fclose(fR);
  if(remove("./2.lzp") !=0 )
    cout<<"删除压缩文件失败"<<endl;
}
