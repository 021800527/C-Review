/*
 * 试编写一个算法，判断给定的二叉树是否是二叉排序树
 */
#include <iostream>
using namespace std;
typedef struct BiTNode{
    int data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
/*
 * predt为全局变量，保存当前结点中序前驱的值，初始值为负无穷大
 */
int predt = -32767;
int JudgeBST(BiTree bt){
    int b1 , b2;
    /*
     * 空树
     */
    if (bt == NULL)
        return 1;
    else
    {
        /*
         * 判断左子树是否是二叉排序树
         */
        b1 = JudgeBST(bt->lchild);
        /*
         * 若左子树返回值为0或前驱大于等于当前结点
         */
        if (b1 ==0 || predt>=bt->data)
        /*
         * 则不是二叉排序树
         */
            return 0;
        /*
         * 保存当前结点的关键字
         */
        predt = bt -> data;
        /*
         * 判断右子树
         */
        b2 = JudgeBST(bt->rchild);
        /*
         * 返回右子树结果
         */
        return b2;

    }
}
