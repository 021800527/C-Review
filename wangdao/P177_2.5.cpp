/*
 * 编程求以孩子兄弟表示法春初的森林的叶子结点数
 */
#include <iostream>
using namespace std;
typedef struct  node{
    /*
     * 数据域
     */
    int data;
    /*
     * 孩子与兄弟域
     */
    struct node *fch,*nsib;
}*Tree;
/*
 * 计算以孩子兄弟表示法存储的森林的叶子数
 */
int Leaves(Tree t){
    /*
     * 树空返回0
     */
    if (t == NULL)
        return 0;
    /*
     * 若结点无孩子，则该结点必是叶子
     */
    if (t ->fch == NULL)
        /*
         * 返回叶子结点和其兄弟子树中的叶子结点数
         */
        return 1+Leaves(t -> nsib);
    /*
     * 孩子子树和兄弟子树中叶子数之和
     */
    else
        return Leaves(t->fch) + Leaves(t -> nsib);

}