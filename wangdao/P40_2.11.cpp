/*
 * 设C = {a1,b1,a2,b2,...,an,bn}为线性表，采用带头结点的hc单链表存放，设计一个就地算法，将其拆分为两个线性表，使得A = {a1,a2,...,an}
 * B={bn,...,b2,b1}
 */
#include <iostream>
using namespace std;
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;
LinkList DisCreat_2(LinkList &A){
    /*
     * 创建B表表头
     */
    LinkList B = (LinkList)new LNode();
    /*
     * B表的初始化
     */
    B->next = NULL;
    /*
     * q为工作指针
     */
    LNode *p = A->next,*q;
    /*
     * r始终指向A的尾结点
     */
    LNode *ra = A;
    while (p!=NULL){
        /*
         * 将p链到A的表尾
         */
        ra ->next = p;
        ra = p;
        p = p->next;
        /*
         * 头插后，*p将断链，因此用q记忆*p的后端
         */
        if (p!=NULL) q = p->next;
        /*
         * 将*p插入到B的前端
         */
        p ->next = B->next;
        B ->next =p;
        p = q;

    }
    /*
     * A尾结点的next域置空
     */
    ra ->next =NULL;
    return B;
}