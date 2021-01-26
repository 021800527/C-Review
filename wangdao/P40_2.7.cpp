/*
 * 设在一个带表头结点的单链表中所有元素结点的数据值无序，试编写一个函数，删除表中所有介于给定的两个值（作为函数参数给出）质检的元素的元素（若存在）
 */
#include <iostream>
using namespace std;
typedef struct LNode{
    int data;
    struct LNode *next;
}*LinkList,LNode;
void Del_S_T(LinkList &L,int s,int t){
    LNode *p = new LNode();
    p = L ->next;
    LNode *pre = new LNode();
    pre = L;
    while (p!=NULL){
        if (p->data<=t&&p->data>=s){
            pre->next =p->next;
            p = p->next;
        } else {
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
    a ->data = 1;
    b ->data = 2;
    c ->data = 3;
    L ->next = a;
    a ->next = b;
    b ->next = c;
    c ->next = NULL;
    Del_S_T(L,0,2);
    while (L->next!=NULL) {
        cout << L->next->data << endl;
        L = L -> next;
    }
    return 0;
}