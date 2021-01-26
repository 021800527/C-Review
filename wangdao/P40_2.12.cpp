/*
 * 在一个递增有序的线性表中，有数值相同的元素存在。若存储方式为单链表，设计算法去掉数值相同的元素，使表中不再有重复的元素
 * 例如（7，10，10，21，30，42，42，51，70）将变为（7，10，21，30，42，51，70）
 */
#include <iostream>
using namespace std;
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;
void Del_same(LinkList &L){
    LNode *p = new LNode();
    LNode *pre = new LNode();
    p = L->next ;
    pre = L;
    while (p!=NULL){
        if (p->data == pre->data)
        {
            pre ->next = p->next;
            p = p ->next;
        }
        else
        {
            pre = p;
            p = p->next;
        }
    }
}
int main(){
    LNode *L = new LNode();
    LNode *a = new LNode();
    LNode *b = new LNode();;
    LNode *c = new LNode();;
    LNode *d = new LNode();;
    LNode *e = new LNode();;
    LNode *f = new LNode();;
    LNode *g = new LNode();;
    LNode *h = new LNode();;
    LNode *i = new LNode();;
    LNode *j = new LNode();;
    LNode *k = new LNode();;
    a ->data = 7;
    b ->data = 10;
    c ->data = 10;
    d ->data = 21;
    e ->data = 30;
    f ->data = 42;
    g ->data = 42;
    h ->data = 42;
    i ->data = 51;
    j ->data = 70;
    L ->next = a;
    a ->next = b;
    b ->next = c;
    c ->next = d;
    d ->next = f;
    f ->next = g;
    g ->next = h;
    h ->next = i;
    i ->next = j;
    j ->next =NULL;
    Del_same(L);
    while (L->next!=NULL) {
        cout << L->next->data << endl;
        L = L -> next;
    }
    return 0;
}