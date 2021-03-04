/*
 *二叉树的带权路径长度(WPL)是二叉树中所有叶结点的带权路径长度之和。给定一棵二叉树T，采用二叉链表存储，结点结构为：

    其中叶结点的weight域保存该结点的非负权值。设root为指向T 的根结点的指针，请设计求T的WPL 的算法，要求：
    1） 给出算法的基本设计思想；

    2） 使用C 或C++语言，给出二叉树结点的数据类型定义；

    3)   根据设计思想，采用C 或C++语言描述算法，关键之处给出注释。
 */
#include <iostream>
using namespace std;
typedef struct BiTNode{
    int weight;
    struct BiTNode *left,*right;
}BiTNode,*BiTree;
int wpl_PreOrder(BiTree root,int deep){
    /*
     * 定义一个static变量存储wpl
     */
    static int wpl = 0;
    /*
     * 若为叶结点，则累计wpl
     */
    if (root->left == NULL && root -> right == NULL)
        wpl += deep*root->weight;
    /*
     * 若左子树不空，则对左子树递归遍历
     */
    if (root->left != NULL)
        wpl_PreOrder(root->left,deep+1);
    /*
     * 若右子树不空，则对左子树递归遍历
     */
    if (root->right != NULL)
        wpl_PreOrder(root->right,deep+1);
    return wpl;
}
int WPL(BiTree root){
    return wpl_PreOrder(root,0);
}


