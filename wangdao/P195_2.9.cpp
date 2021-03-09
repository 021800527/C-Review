/*
 * 设计一个算法，求出给定二叉排序树中最小和最大的关键字
 */
#include <iostream>
using namespace std;
typedef struct BiTNode{
    int data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
/*
 * 求出二叉排序树中最小关键字结点
 */
int MinKey(BiTNode *bt){
    while (bt -> lchild != NULL)
        bt=bt->lchild;
    return bt->data;
}
/*
 * 求出二叉排序树中最大关键字结点
 */
int MaxKey(BiTNode *bt){
    while (bt -> rchild != NULL)
        bt = bt -> rchild;
    return bt ->data;
}