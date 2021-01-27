/*
 * 设有一个带头结点的循环单链表，其结点均为正整数。设计一个算法，反复找出单链表中结点值最小的结点并输出，
 * 然后将该结点从中删除，知道单链表空为止，再删除表头结点
 */
#include <iostream>
using namespace std;
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;
/*
 * 本算法实现每次删除循环单链表中的最小元素，直到链表空为止
 */
void Del_All(LinkList &L){
    LNode *p,*pre,*minp,*minpre;
    /*
     * 表不空，循环
     */
    while (L->next!=NULL)
    {
        /*
         * p为工作指针，pre指向其前驱
         */
        p = L->next;
        pre = L;
        /*
         * minp指向最小值结点
         */
        minp = p;
        minpre =pre;
        while (p!=L){
            if (p->data<minp->data){
                /*
                 * 找到值更小的结点
                 */
                minp = p;
                minpre = pre;
            }
            /*
             * 查找下一个结点
             */
            pre = p;
            p = p->next;
        }
        /*
         * 输出最小值结点元素
         */
        cout<<minp->data<<endl;
        /*
         * 最小值结点从表中断开
         */
        minpre ->next = minp ->next;
        /*
         * 释放空间
         */
        free(minp);
    }
    /*
     * 释放头结点
     */
    free(L);
}