/*
 * 设A和B是两个单链表（带头结点），其中元素递增有序。设计一个算法从A和B中的公共元素产生单链表C，要求不破坏A、B的结点
 */
#include <iostream>
using namespace std;
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;
/*
 * 算法思想：表A、B都有序，可从第一个元素起依次比较A、B两表的元素。
 * 若元素值不等，则值小的指针往后移，若元素值相同，则创建一个值等于两结点的元素值的新结点，使用尾插法插入到新链表中
 * 并将两个原表指针后移一位，直到其中一个链表遍历到表尾
 */
void Get_Common(LinkList &A,LinkList &B){
    /*
     * 本算法产生单链表A和B的公共元素的单链表C
     */
    LNode *p = A->next,*q = B->next,*r,*s;
    /*
     * 建立表C
     */
    LinkList C = (LinkList)new LNode();
    /*
     * r始终指向C的尾结点
     */
    r = C;
    while (p!=NULL&&q!=NULL){
        /*
         *若A的当前元素较小，后移指针
         */
        if (p->data < q->data)
            p = p ->next;
        else if (p->data > q->data)
            /*
             * 若B的当前元素较小，后移指针
             */
            q = q ->next;
        else
            /*
             * 找到公共元素结点
             */
        {
            LNode *s = new LNode();
            /*
             * 复制产生结点*s
             */
            s ->data = p ->data;
            /*
             * 将*s链接到C上（尾插法）
             */
            r ->next = s;
            r = s;
            p = p->next;
            q = q->next;
        }
    }
    /*
     * 置C尾结点指针为空
     */
    r->next = NULL;
}