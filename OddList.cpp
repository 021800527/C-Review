#include <stdlib.h>
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;
/*
 * 初始化一个循环单链表
 */
bool InitList(LinkList &L){
    L=(LNode *)malloc(sizeof(LNode));
    if (L==NULL)
        return false;
    L->next = L;
    return true;
}
/*
 * 判断循环链表是否为空
 */
bool Empty(LinkList &L){
    if(L->next == L)
        return true;
    else
        return false;
}
/*
 * 判断结点p是否为循环单链表的表尾结点
 */
bool isTail(LinkList L,LNode *p){
    if (p->next == L)
        return true;
    else
        return false;
}
int main(){

}