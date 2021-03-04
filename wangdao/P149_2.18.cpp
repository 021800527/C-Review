/**
 * 写出在中序线索二叉树里查找指定结点在后序的前驱结点的算法
 */
/*
 * 算法思想：在后序序列中，若结点p有右子女，则右子女是其前驱。
 * 若无右子女而有左子女，则左子女是其前驱
 * 若结点p左、右结点均无
 * 设其中序左线索指向某祖先结点f（p是f右子树中按中序遍历的第一个结点），若f有左子女，则其左子女是结点p在后序下的前驱
 * 若f无左子女，则顺其前驱找双亲的双亲，一直找到双亲有左子女（这时左子女是p的前驱）。
 * 还有一个情况，若p是中序遍历的第一个结点，则结点p在中序和后序下均无前驱
 */
#include <iostream>
using namespace std;
typedef struct BiTNode{
    int val;
    struct BiTNode *left,*right;
    int rtag;
    int ltag;
}BiTNode,*BiTree;
/*
 * 在中序线索二叉树t中，求指定结点p在后续下的前驱结点q
 */
BiTree InPostPre(BiTree t,BiTree p){
    BiTree q;
    /*
     * 若p有右子女，则右子女是其后序前驱
     */
    if (p->rtag == 0)
    {
        q = p -> right;
    }
    /*
     * 若p只有左子女，则左子女是其后序前驱
     */
    else if (p -> ltag ==0)
        q = p -> left;
    /*
     * p是中序序列第一节点，无后序前驱
     */
    else if (p -> left == NULL)
        q = NULL;
    /*
     * 顺左线索向上找p的祖先，若存在，再找祖先的左子女
     */
    else
    {
        while (p->ltag == 1 && p->right == NULL)
            p = p -> left;
        /*
         * p结点的祖先的左子女是其后序前驱
         */
        if (p->ltag == 0)
            q = p -> left;
        /*
         * 仅有单支树（p是叶子），已到根结点，p无后序前驱
         */
        else
            q = NULL;
    }
    return q;
}