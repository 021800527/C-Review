#include <iostream>
using namespace std;
typedef struct BSTNode{
    int data;
    struct BSTNode *lchild,*rchild;
}BSTNode,*BiTree;
/*
 * 查找
 */
BSTNode *BST_Search(BiTree T , int key , BSTNode *&p){
    p = NULL;
    while (T!=NULL && key != T ->data){
        p = T;
        if (key < T ->data)
            T = T ->lchild;
        else
            T = T ->rchild;
    }
    return T;
}
/*
 * 插入
 */
int BST_Insert(BiTree &T , int k){
    if (T ==NULL){
        T = (BiTree)malloc(sizeof(BSTNode));
        T -> data = k;
        T ->lchild = T ->rchild = NULL;
        return 1;
    }
    else if (k == T -> data)
        return 0;
    else if (k < T -> data)
        return BST_Insert(T -> lchild,k);
    else
        return BST_Insert(T -> rchild,k);
}