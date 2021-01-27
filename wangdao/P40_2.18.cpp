/*
 * 有两个循环单链表，链表头指针分别为h1和h2，编写一个函数将链表h2链接到链表h1之后，要求链接后的链表仍保持循环链表形式
 */
/*
 * 将循环链表h2链接到循环链表h1之后，使之仍保持循环链表
 */
#include <iostream>
using namespace std;
typedef struct DLNode{
    int data;
    struct DLNode *prior,*next;
}DLNode,*DLinkList;
DLinkList Link(DLinkList &h1,DLinkList &h2)
{
    /*
     * 分别指向两个链表的尾结点
     */
    DLNode *p, *q;
    p = h1;
    /*
     * 寻找h1的尾结点
     */
    while (p->next != h1)
        p = p ->next;
    q =h2;
    /*
     * 寻找h2的尾结点
     */
    while (q->next != h2)
        q = q ->next;
    /*
     * 将h2链接到h1之后
     */
    p->next =h2;
    /*
     * 令h2的尾结点指向h1
     */
    q ->next = h1;
    return h1;
}