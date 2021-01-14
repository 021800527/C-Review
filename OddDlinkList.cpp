#include <stdlib.h>
typedef struct DNode{
    int data;
    struct DNode *prior, *next;
}DNode,*DLinkList;
/*
 * 初始化空的循环双链表
 */
bool InitDLinkList(DLinkList &L){
    /*
     * 分配一个头结点
     */
    L = (DNode *)malloc(sizeof(DNode));
    /*
     * 内存不足，分配失败
     */
    if (L==NULL)
        return false;
    /*
     * 头结点的prior指向头结点
     */
    L->prior = L;
    /*
     * 头结点的next指向头结点
     */
    L->next = L;
    return true;
}
/*
 * 判断循环双链表是否为空
 */
bool Empty(DLinkList L){
    if (L->next==L)
        return true;
    else
        return false;
}
/*
 * 判断结点p是否为循环双链表的表尾结点
 */
bool isTail(DLinkList L,DNode *p){
    if (p->next==L)
        return true;
    else
        return false;
}
/*
 *在p结点之后插入s结点
 */
bool InsertNextDNode(DNode *p,DNode *s){
    s->next = p->next;
    p->next->prior = s;
    s->prior = p;
    p->next = s;
}
/*
 * 栓除p的后继结点q
 */
