/**
 * 假设二叉树采用二叉链表存储结构，设计一个算法，求先序遍历序列中第k（1<=k<=二叉树中结点个数）个结点的值
 */
#include <iostream>
using namespace std;
typedef struct BiTNode{
    int val;
    struct BiTNode *left,*right;
}BiTNode,*BiTree;
/*
 * 遍历序号的全局变量
 */
int i = 1;
/*
 * 本算法查找二叉树先序遍历序列中第k个结点的值
 */
int PreNode(BiTree b , int k ){
    /*
     * 空结点，则返回特殊字符
     */
  if (b==NULL)
      return '#';
  /*
   * 相等，则当前结点即为第k个结点
   */
  if (i==k)
      return b->val;
  /*
   * 下一个结点
   */
  i++;
  /*
   * 在左子树中递归寻找
   */
  auto ch = PreNode(b->left,k);
  /*
   * 在左子树中，则返回该值
   */
  if (ch!='#')
      return ch;
  /*
   * 在右子树中递归训中
   */
  ch = PreNode(b->right,k);
    return ch;
}