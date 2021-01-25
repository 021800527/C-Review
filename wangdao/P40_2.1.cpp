/*
 * 设计一个递归算法，删除不带头结点的单链表L中所有值为x的节点
 */
#include <iostream>
using namespace std;
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;
void Del_x_3(LinkList &L,int x){
    /*
     * 递归实现在单链表L中删除值为x的结点
     */
    LNode *p ; /* p指向待删除结点 */
    if (L == NULL) /* 递归出口 */
        return;
    if (L->data == x){
        /*
         * 若L所指结点的值为x
         * 删除*L，并让L指向下一节点
         */
        p = L;
        L = L ->next;
        free(p);
        Del_x_3(L,x);
    }
    else
        /*
         * 若L所指结点的值不为x
         */
        Del_x_3(L->next,x);
}