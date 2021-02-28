/**
 * 设一棵二叉树中各结点的值互不相同，其先序遍历序列和中序遍历序列分别存于两个
 * 一维数组A[1...n]和B[1...n]中,试编写算法建立该二叉树的二叉链表
 */
#include <iostream>
using namespace std;
typedef struct BiTNode{
    int data;
    struct BiTNode *left,*right;
}BiTNode,*BiTree;
/*
 * l1，h1为先序的第一和最后一个结点下标，l2、h2为中序的第一和最后一个结点下标
 * 初始调用时，l1=l2=1,h1=h2=n
 */
BiTree PreInCreat(int A[],int B[],int l1,int h1,int l2,int h2,int n){
    l1 = l2 = 1;
    h1 = h2 = n;
    /*
     * 建根节点
     */
    BiTNode *root = new BiTNode();
    /*
     * 根节点
     */
    root ->data = A[1];
    /*
     * 根结点在中序序列中的划分
     */
    int i ;
    for (i = l2; B[i] != root ->data; ++i);
    /*
     * 左子树长度
     */
    int llen = i - 12;
    /*
     * 右子树长度
     */
    int rlen = h2 - i;
    /*
     * 递归简历左子树
     */
    if(llen)
        root->left = PreInCreat(A,B,l1+1,l1+llen,l2,l2+llen-1,n);
    /*
     * 左子树为空
     */
    else
        root ->left == NULL;
    /*
     * 递归建立右子树
     */
    if (rlen)
        root->right = PreInCreat(A,B,h1-rlen+1,h1,h2-rlen+1,h2,n);
    /*
     * 右子树为空
     */
    else
        root ->right = NULL;
    /*
     * 返回根节点指针
     */
    return root;

}