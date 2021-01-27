/*
 * 设计一个算法用于判断带头结点的循环双链表是否对称
 */
/*
 * 本算法从两头扫描循环双链表，以判断链表是否对称
 */
#include <iostream>
using namespace std;
typedef struct DLNode{
    int data;
    struct DLNode *prior,*next;
}DLNode,*DLinkList;
int Symmetry(DLinkList L){
    /*
     * 两头工作指针
     */
    DLNode *p = L->next;
    DLNode *q = L->prior;
    /*
     * 循环跳出条件
     */
    while (p!=q&&q ->next!=p){
        /*
         * 所指结点值相同则继续比较
         */
        if (p->data == q->data)
        {
            p = q ->next;
            q = q->prior;
        }
        /*
         * 否则返回0
         */
        else
            return 0;
        /*
         * 比较结束后返回1
         */
        return 1;
    }
}