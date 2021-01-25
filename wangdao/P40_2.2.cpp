/*
 * 在带头结点的单链表L中，删除所有值为x的结点，并释放其空间，假设值为x的结点不唯一，试编写算法以实现上述操作。
 */
#include <iostream>
using namespace std;
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;
void Del_x_3(LinkList &L,int x){
    /*
     * 递归实现在单链表L中删除值为x的结点
     */
    LNode *p ; /* p指向待删除结点 */
    if (L == NULL) /* 递归出口 */
        return;
    if (L->data == x){
        /*
         * 若L所指结点的值为x
         * 删除*L，并让L指向下一节点
         */
        p = L;
        L = L ->next;
        free(p);
        Del_x_3(L,x);
    }
    else
        /*
         * 若L所指结点的值不为x
         */
        Del_x_3(L->next,x);
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
    LNode *p;
    p = L;
    while (p!=NULL){
        cout<<p->data<<endl;
        p = p->next;
    }
    Del_x_3(L,2);
    p = L;
    while (p!=NULL){
        cout<<p->data<<endl;
        p = p->next;
    }
    return 0;
}