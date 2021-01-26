/*
 * 试编写算法将带头结点的单链表就地逆置，所谓“就地”是指辅助空间复杂度为O（1）
 */
#include <iostream>
using namespace std;
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;
LinkList Reversed(LinkList &L){
    LNode *p = new LNode();
    p = NULL;
    while (L->next!=NULL)
    {
        LNode *s  =new LNode();
        s->next = p;
        s->data = L->next->data;
        p = s;
        L = L->next;
    }
    return p;
}
int main(){
    LNode *L = new LNode();
    LNode *a = new LNode();
    LNode *b = new LNode();;
    LNode *c = new LNode();;
    a ->data = 1;
    b ->data = 2;
    c ->data = 3;
    L ->next = a;
    a ->next = b;
    b ->next = c;
    c ->next = NULL;
    LNode *p = Reversed(L);
    while (p!=NULL) {
        cout << p->data << endl;
        p = p -> next;
    }
    return 0;
}