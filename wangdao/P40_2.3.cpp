/*
 * 设L为带头结点的单链表，编写算法实现从尾时到头反向输出每个节点的值
 */
#include <iostream>
using namespace std;
typedef struct LNode{
    int data;
    LNode *next;
}*LinkList,LNode;
void Reserved(LinkList &L){
    if (L->next!=NULL)
        Reserved(L->next);
    if (L!=NULL)
        cout<<L->data<<endl;
}
int main(){
    LNode *L = new LNode();
    LNode *a = new LNode();
    LNode *b = new LNode();;
    LNode *c = new LNode();;
    a ->data = 2;
    b ->data = 3;
    c ->data = 4;
    L ->data = 1;
    L ->next = a;
    a ->next = b;
    b ->next = c;
    c ->next = NULL;
    Reserved(L);
    return 0;
}