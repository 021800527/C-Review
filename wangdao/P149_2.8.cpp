/**
 * 假设二叉树采用二叉链表存储结构存储，试设计一个算法，计算一棵给定二叉树的所有双分支结点个数
 */

#include<iostream>
using namespace std;
typedef struct BiTNode {
    int val ;
    struct BiTNode *left,*right;
}BiTNode,*BiTree;
int DsonNodes(BiTree b){
    if (b==NULL)
        return 0;
    /*
     * 双分支结点
     */
    else if (b->left != NULL && b->right != NULL)
        return DsonNodes(b->left)+DsonNodes(b->right)+1;
    else
        return DsonNodes(b->left)+DsonNodes(b->right);
}