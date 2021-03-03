/**
 * 试设计判断两颗二叉树是否相似的算法
 * 所谓二叉树T1和T2相似，指的是T1和T2都是空的二叉树或都只有一个根结点
 * 或T1的左子树和T2的左子树是相似的
 * 且T1的右子树和T2的右子树是相似的
 */
/*
 * 采用递归的算法判断两棵二叉树是否相似
 */
#include <iostream>

typedef struct BiTNode{
    int val;
    struct BiTNode *left,*right;
}BiTNode,*BiTree;
int similar(BiTree T1,BiTree T2){
    int leftS,rightS;
    /*
     * 两树皆空
     */
    if (T1 == NULL && T2 == NULL)
        return 1;
    /*
     * 只有一树为空
     */
    else if (T1 == NULL || T2 == NULL)
        return 0;
    else
    {
        leftS = similar(T1->left , T2 ->left);
        rightS = similar(T1->right, T2->right);
        return leftS&&rightS;
    }
}