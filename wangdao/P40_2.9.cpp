/*
 * 给定一个带表头结点的单链表，设head为头指针，结点结构为（data，next），data为整型元素，next为指针，试写出算法：
 * 按递增次序输出单链表中各结点的数据元素，并释放结点所占的空间
 * 要求：不允许使用数组作为辅助空间
 */
#include <iostream>
using namespace std;
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;
/*
 * head是带头结点的单链表的头指针，本算法按递归增顺序输出单链表中的数据元素
 */
void Min_Delete(LinkList &head){
    /*
     * 循环到仅剩头结点
     */
    LNode *pre = new LNode();
    LNode *p = new LNode();
    LNode *u = new LNode();
    while (head->next==NULL)
    {
        /*
         * pre为元素最小值结点的前驱结点的指针
         */
        pre = head;
        /*
         * p为工作指针
         */
        p = pre->next;
        while (p->next!=NULL){
            if (p->next->data<pre->next->data)
                /*
                 * 记住当前最小值结点的前驱
                 */
                pre = p;
                p = p->next;
        }
        /*
         * 输出元素最小值结点的数据
         */
        cout<<pre->next->data<<endl;
        /*
         * 删除元素最小的结点，释放节点空间
         */
        u = pre ->next;
        pre->next = u ->next;
        free(u);
    }
    /*
     * 释放头结点
     */
    free(head);
}