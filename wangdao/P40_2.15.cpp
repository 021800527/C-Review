/*
 * 已知两个链表A和B分别表示两个集合，其元素递增排列。编制函数，求A与B的交集，并存放于A链表中
 */
#include <iostream>
using namespace std;
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;
LNode *Union(LinkList &A,LinkList &B){
    LNode *pa = new LNode();
    pa  = A->next;
    LNode *pb = new LNode();
    pb = B->next;
    LNode *res = new LNode();
    res = A;
    while (pa&&pb){
        if (pa->data<pb->data)
        {
            LNode *u =new LNode();
            u = pa;
            pa = pa->next;
            free(u);
        }
        else if (pa->data > pb ->data)
            {
                LNode *u = new LNode();
                u = pb;
                pb = pb ->next;
                free(u);
            }
            else
            {
                res ->next = pa;
                res = res->next;
                pa = pa ->next;
                LNode *u = new LNode();
                u = pb;
                pb = pb ->next;
                free(u);
            }
    }
    while (pa){
        LNode *u = new LNode();
        u = pa;
        pa = pa->next;
        free(u);
    }
    while (pb){
        LNode *u = new LNode();
        u = pb;
        pb = pb->next;
        free(u);
    }
    res ->next =NULL;
    free(B);
    return A;
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

    LNode *lb = new LNode();
    LNode *z = new LNode();
    LNode *x = new LNode();
    z ->data = 7;
    x ->data = 10;
    lb ->next =z;
    z ->next =x;
    x ->next = NULL;
    Union(L,lb);
    while (L->next!=NULL) {
        cout << L->next->data << endl;
        L = L -> next;
    }
    return 0;
}