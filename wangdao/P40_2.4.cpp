/*
 * 试编写在带头结点的单链表L中删除一个最小值结点的高效算法（假设最小值结点是唯一的）
 */
#include <iostream>
using namespace std;
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;
LinkList Delete_Min(LinkList &L){
    /*
     * L是带头结点的单链表，本算法删除其最小值结点
     */
    LNode *pre = L,*p = pre -> next;
    LNode *minpre=pre;
    LNode *minp = p;
    /*
     * 找到比之前找到的最小值结点更小的结点
     */
    while (p!=NULL){
        if (p->data < minp->data)
        {
            minp = p;
            minpre = pre;
        }
        pre = p;
        p = p -> next;
    }
    /*
     * 删除最小值结点
     */
    minpre ->next =minp ->next;
    free(minp);
    return L;
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
    LNode *p = Delete_Min(L);
    while (p!=NULL){
        cout<<p->data<<endl;
        p = p->next;
    }
    return 0;
}