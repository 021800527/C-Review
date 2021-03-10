/*
 * 编写一个递归算法，在一棵有n个结点的、随机建立起来的二叉排序树上查找第k（1<=k<=n）小的元素
 * 并返回指向该结点的指针。要求算法的平均时间复杂度为O(log2n)
 * 二叉排序树的每个结点中除data，lchild，rchild等数据成员外，增加一个count成员
 * 保存以该结点为根的子树上的结点个数
 */
#include <iostream>
using namespace std;
typedef struct BiTNode{
    int data;
    int count;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
/*
 * 在以t为根的子树上寻找第k小的元素，返回其所在结点的指针
 * k从l1开始计算
 * 在树结点中增加一个count数据成员，存储以该结点为根的子树的结点个数
 */
BiTNode *Search_Small(BiTNode *t,int k){
    if (k<1||k>t->count) return NULL;
    if (t->lchild == NULL){
        if (k==1) return t;
        else
            return Search_Small(t->rchild,k-1);
    } else{
        if (t->lchild->count == k-1) return t;
        if (t->lchild->count > k-1) return Search_Small(t->lchild,k);
        if (t->lchild->count < k-1)
            return Search_Small(t->rchild,k-(t->lchild->count+1));
    }
}