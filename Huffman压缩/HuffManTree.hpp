#pragma once 

//#include "FileCompressHuff.h"
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <assert.h>
using namespace std;


template <class W>//结点类型
struct HuffmanTreeNode  //结点也是二叉树
{
  HuffmanTreeNode(const W& weight = W() )//W内置 ---传0， 自定义类型 ，必须需要有W的构造函数
    :_pLeft(nullptr)
     ,_pRight(nullptr)
     ,_pParent(nullptr)
     ,_weight(weight)
  {}
  HuffmanTreeNode<W>* _pLeft;
  HuffmanTreeNode<W>* _pRight;
  HuffmanTreeNode<W>* _pParent;
  W _weight;//结点的权值 节点是CharInfo一个结构体 直传权值，不能确定对应字符
};

template<class W>
class Less
{
  typedef HuffmanTreeNode<W> Node;

  public:

  bool operator()( Node* Left, Node* Right)//()运算符重载,因为需要重新定义（）内部的两个数的比较规则
  {
    return Left->_weight > Right->_weight;//内置默认小于，优先级队列默认大堆
  }
};


template <class W>
class HuffmanTree
{

  typedef HuffmanTreeNode<W> Node;
 
  public:

  HuffmanTree()
    :_pRoot(nullptr)
  {}

  //构造
 HuffmanTree(const std::vector<W>& vWeight,const W& invalue)//invalue是在构造Huffman树期间避免将权值为0的结点构造进去
  {
    for(auto e : vWeight)
    if(e == invalue)  //这里需要 ==的重载  两者都是  W类型 均处在CharInfo中 
      continue;     //权值为0的字符不构建Huffman树中
    CreateHuffManTree(vWeight, invalue); 
  }

  //用优先级队列做森林
 void CreateHuffManTree(const std::vector<W>& vWeight,const  W& invalue ) //数组传权值数
  {
    //1  构建森林
    //优先级队列 默认，大堆 我们改一改，我们需要小堆
    std::priority_queue<Node*, std::vector<Node*>, Less<W>> q; //注意，向堆里插入时需要比较(用权值比较)，所以比较器需要重写 
    for( auto& e :vWeight )
    {
      if(e._count != invalue._count)//过滤掉出现次数为0的字符
      q.push(new Node(e));//new一个节点---------新二叉树，  加入优先级队列
    }
    
    //2 每次取两颗权值最小的二叉树,构造出他们的父树 
    while(q.size() > 1)//森林中超过两棵树
    {
        Node* left = q.top();
        q.pop();

        Node* right =q.top();
        q.pop();

        Node* parent = new Node();//我们需要这个哈夫曼树能够在退出时存在，所以new一个树结点
        parent->_pLeft = left;
        parent->_pRight = right;
        parent->_weight =left->_weight + right->_weight;//重载+   注意 返回值类型为  W 不是int 
        
        left->_pParent = parent;
        right->_pParent = parent;

        q.push(parent);
    }

   _pRoot =  q.top();//剩下的最后一棵树就是我们想要的Huffman树  带权路径最小的树
  }


  void DestroyHuffmanTree(Node*& pRoot)//修改指针的指向
  {
    if(pRoot)//存在与否
    {
      DestroyHuffmanTree(pRoot->_pLeft);
      DestroyHuffmanTree(pRoot->_pRight);
      delete pRoot;
      pRoot =nullptr;//  这里千万小心  ，我们要改指针，需要传二级指针或者一级指针的引用
    }
  }

//获取根节点
Node* GetRoot()
{
  return _pRoot;
}

~HuffmanTree()
{
  DestroyHuffmanTree(_pRoot);
}

  private: 
  Node* _pRoot;
};


//测试Huffman树
//void TestHuffmanTree()
//{
//  vector<int> v ={3, 1, 5, 7};
//  HuffmanTree<int> t(v,0);
//}



