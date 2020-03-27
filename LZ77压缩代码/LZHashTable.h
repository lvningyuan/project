#pragma once 
#include "common.h"

class LZHashTable
{

  public:
    LZHashTable(USH size);
  
    ~LZHashTable();

   void Insert(USH& matchHead, UCH ch, USH pos, USH& hashAddr);//匹配头 ，字符 ，在WSIZE的位置， 哈希地址

   void HashTable(USH& hashaddr, UCH ch);//哈希函数
  
   void HashFunc(USH& hashAddr, UCH ch);
   
   USH  GetNext(USH matchHead);//获取下一个头下标

   void upDate();
  
  private:
   USH H_SHIFT();//配合上面的哈希函数使用的 

  private:
   USH*  _prev;//解决哈希冲突的数组
   USH*  _head;
};
