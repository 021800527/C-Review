/*
 * 设计一个算法，求出指定结点在给定二叉排序树中的层次
 */
#include <iostream>
using namespace std;
typedef struct BiTNode{
    int data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
/*
 * 本算法计算给定结点*p在二叉排序树中的层次
 */
int level(BiTree bt , BiTNode *p){
    /*
     * 统计查找次数
     */
    int n = 0 ;
    BiTree t = bt;
    if (bt != NULL){
        n++;
        while (t -> data != p -> data){
            /*
             * 在左子树中查找
             */
            if (p->data<t->data)
                t = t -> lchild;
            /*
             * 在右子树中查找
             */
            else
                t = t -> rchild;
            /*
             * 层次加1
             */
            n++;
        }
    }
    return n;
}