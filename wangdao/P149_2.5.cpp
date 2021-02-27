/**
 * 假设二叉树采用二叉链表存储结构，设计一个非递归算法求二叉树的高度
 */
/*
 * 采用层次遍历的非递归方法求解二叉树的高度
 */
#include <iostream>
#include <queue>
using namespace std;
typedef struct BiTNode{
    int data;
    struct BiTNode *left,*right;
}BiTNode,*BiTree;
int Btdepth(BiTree T){
    if (!T)
        return 0;
    queue<BiTNode*>q;
    q.push(T);
    int depth = 0;
    while (!q.empty()){
        auto node = q.front();
        q.pop();
        if (node->left!=NULL)
            q.push(node->left);
        if (node->right!=NULL)
            q.push(node->right);
        depth ++;
    }
    return depth;
}