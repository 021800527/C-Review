/*
 * 两个整数序列A=a1，a2,a3,...,am和B=b1,b2,b3,...,bn已经存入两个单链表中，设计一个算法
 * 判断序列B是否是序列A的连续子序列
 */
/*
 * A和B分别是数据域为整数的单链表，本算法判断B是否是A的子序列
 */
#include <iostream>
using namespace std;
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;
int Pattern(LinkList A,LinkList B){
    /*
     * p为A链表的工作指针，假设A和B均为无头结点
     */
    LNode *p = new LNode();
    p = A;
    /*
     * pre记住每趟比较中A链表的开始结点
     */
    LNode *pre = new LNode();
    pre = p;
    /*
     * q是B链表的工作指针
     */
    LNode *q = new LNode();
    q = B;
    while (p&&q)
        /*
         * 结点值相同
         */
        if (p->data == q->data){
            p = p->next;
            q = q->next;
        } else{
            pre =pre ->next;
            /*
             * A链表新的开始比较结点
             */
            p =pre;
            /*
             * q从B链表第一个结点开始
             */
            q =B;
        }
    /*
     * B已经比较结束
     */
    if (q==NULL)
        /*
         * 说明B是A的子序列
         */
        return 1;
        /*
         * B不是A的子序列
         */
    else
        return 0;
}