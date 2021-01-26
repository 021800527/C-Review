/*
 * 假设有两个按元素值递增次序排列的线性表，均以单链表形式存储。
 * 请编写算法将两个单链表归并为一个按元素值递减次序排列的单链表，并要求利用原来两个单链表的结点存放归并后的单链表
 */
/*
 * 算法思想：两个链表已经按元素值递增次序排序。将其合并时，均从第一个结点起进行比较，将小的结点链入链表中，同时后移工作指针。
 * 该问题要求结果链表按元素值递减次序排列，故新链表的建立应该采用头插法。
 * 比较结束后，可能会有一个链表非空，此时用头插法将剩下的结点依次插入新链表中即可。
 */
/*
 * 合并两个递增有序链表（带头结点），并使合并后的链表递减排列
 */
#include <iostream>
using namespace std;
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;
/*
 * 合并两个递增有序链表（带头节点）,并使合并后的链表递减排列
 */
void MergeList(LinkList &La,LinkList &Lb){
    /*
     * 分别是表La和Lb的工作指针
     */
    LNode *r,*pa = La->next,*pb = Lb ->next;
    /*
     * La作为结果链表的头指针，先将结果链表初始化为空
     */
    La ->next =NULL;
    /*
     * 但两链表均不为空时，循环
     */
    while (pa&&pb)
        if (pa->data<=pb->data){
            /*
             * r暂存pa的后继结点指针
             */
            r =pa->next;
            pa ->next = La ->next;
            /*
             * 将pa结点链于结果表中，同时逆置（头插法）
             */
            La ->next = pa;
            /*
             * 恢复pa为当前待比较结点
             */
            pa = r;
        } else{
            /*
             * r暂存pb的后继结点指针
             */
            r = pb->next;
            pb ->next = La ->next ;
            /*
             * 将pb结点链于结果表中，同时逆置（头插法）
             */
            La->next =pb;
            /*
             * 恢复pb为当前待比较结点
             */
            pb = r;
        }
        if (pa)
            /*
             * 通常情况下会剩下一个链表非空，处理剩下的部分。
             */
            pb =pa;
        while (pb){
            r =pb ->next;
            pb ->next = La ->next;
            La ->next = pb;
            pb = r;
        }
        free(Lb);
}