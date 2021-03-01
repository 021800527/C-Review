/*
 * 设树B是一棵采用链式结构存储的二叉树，编写一个把树B中所有结点的左、右子树进行交换的函数
 */
#include <iostream>
using namespace std;
typedef struct BiTNode{
    int val;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
/*
 * 本算法递归地交换二叉树的左、右子树
 */
void swap(BiTree b){
    if (b){
        /*
         * 递归地交换左子树
         */
        swap(b->lchild);
        /*
         * 递归地交换右子树
         */
        swap(b -> rchild);
        /*
         * 交换左、右孩子结点
         */
        BiTNode *temp = b -> lchild;
        b -> lchild = b -> rchild;
        b -> rchild = temp;
    }
}