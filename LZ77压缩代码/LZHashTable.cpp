#include "LZHashTable.h"
#include  <cstring>

const USH HASH_BITS = 15;//1哈希地址   32K最大查找范围   15个比特位
const USH HASH_SIZE = 1 << (HASH_BITS);//哈希表的大小  0x1000 0000 -->32K
const USH HASH_MASK = HASH_SIZE - 1;//哈希掩码


//哈希表构造
LZHashTable::LZHashTable(USH size)//size 将来穿 WSIZE
:_prev(new USH[size * 2])//处理哈希冲突区
,_head(_prev + size)//哈希表区
{
 memset(_prev,0,sizeof(USH) *2 * size);//2*size 大小 ，sizeof(USH) 每个USH位
}

//哈希表析构
LZHashTable::~LZHashTable()
{
  delete []_prev;
  _prev = nullptr;
  _head = nullptr;
}


//matchHead传出查找到的字符串 在查找缓冲区的位置。
//给hashAddr这个地址写ch在 先行缓冲区中的位置pos ,若未发生冲突就直接插入， 否则，处理冲突，
void LZHashTable::Insert(USH& matchHead, UCH ch, USH pos, USH& hashAddr)//hashAddr 上次的hashAddr的后两个
{
  HashFunc(hashAddr,ch);//哈希地址在当前字符的基础上算出来的

  matchHead = _head[hashAddr]; //保存在查找缓冲区的位置
  _prev[pos & HASH_MASK] = _head[hashAddr];//去_prev中处理冲突     与掩码的目的为了防止越界---pos 可能超过32K
  _head[hashAddr] = pos;//让本次在_head冲突位置中  当前字符串的在文件中的pos
}



//本次的哈希地址是在上一次的哈希地址的基础上算出来的
//hashAddr 是前一次计算出的哈希地址  ch 是本次匹配的头一个字符  
//eg::  前一次计算出的哈希地址   abc
//本次需要计算c、的哈希地址      bcd
// 本次匹配中的三个字符中的最后一个是d， 所以本次将hashAddr =bc     ch = d传进来
void  LZHashTable::HashFunc(USH& hashAddr, UCH ch)
{
  hashAddr = ( ( (hashAddr) << H_SHIFT())^ (ch) )& HASH_MASK;
}



USH LZHashTable::H_SHIFT()
{
  return (HASH_BITS + MIN_MATCH - 1) / MIN_MATCH;
}

USH LZHashTable::GetNext(USH matchHead)
{
  return _prev[matchHead & HASH_MASK];//防止matchHead走到右窗 导致越界
}

void LZHashTable::upDate()
{
  for(int i=0; i<WSIZE; ++i)
  {
    if(_head[i] >=  WSIZE)
      _head[i] -= WSIZE;
    else
      _head[i] = 0;
    
    if(_prev[i] >=  WSIZE)
      _prev[i] -= WSIZE;
    else 
      _prev[i] = 0;
  }

}
