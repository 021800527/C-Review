/**
 * 二叉树按二叉链表形式存储，写一个判定给二叉树是否是完全二叉树的算法
 */
/*
 * 本算法判断给定二叉树是否是完全二叉树
 */
#include <iostream>
#include <queue>
using namespace std;
typedef struct BiTNode{
    int val;
    struct  BiTNode *left,*right;
}BiTNode,*BiTree;
bool IsComplete(BiTree T){
    queue<BiTNode*>Q;
    /*
     * 空树为满二叉树
     */
    if (!T)
        return true;
    Q.push(T);
    while (!Q.empty()){
        BiTNode *p = Q.front();
        Q.pop();
        /*
         * 结点非空，将其左、右子树入队列
         */
        if (p)
        {
            Q.push(p -> left);
            Q.push(p -> right);
        }
        /*
         * 结点为空，检查其后是否有非空结点
         */
        else
        {
            while (!Q.empty()){
                p = Q.front();
                Q.pop();
                /*
                 * 结点非空，则二叉树为非完全二叉树
                 */
                if (p)
                    return false;
            }
        }
        return true;
    }
}