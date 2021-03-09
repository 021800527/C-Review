/*
 * 编写一个算法，从大到小输出二叉排序树中所有值不小于k的关键字
 */
#include <iostream>
using namespace std;
typedef struct BiTNode{
    int data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
/*
 * 本算法从大到小输出二叉排序树中所有值不小于k的关键字
 */
void OutPut(BiTNode *bt,int k){
    if (bt == NULL)
        return ;
    /*
     * 递归输出右子树结点
     */
    if (bt -> rchild)
        OutPut(bt->rchild,k);
    /*
     * 只输出大于等于k的结点值
     */
    if (bt->data>=k)
        cout<<bt->data;
    /*
     * 递归输出右子树结点
     */
    if (bt->lchild == NULL)
        OutPut(bt->lchild,k);
}