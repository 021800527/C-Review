#include <stdlib.h>
typedef struct DNode{
    int data;
    struct DNode *prior,*next;
}DNode,*DLinkList;
bool InitDLinkList(DLinkList &L){
    L = (DNode*)malloc(sizeof(DNode));
    if (L==NULL)
        return false;
    L->prior =NULL;
    L->next = NULL;
    return true;
}
void testDlinkList(){
    DLinkList L;
    InitDLinkList(L);
}
bool InsertNextDNode(DNode *p,DNode*s){
    if (p==NULL||s==NULL)
        return false;
    s->next = p->next;
    if(p->next!=NULL)
        p->next->prior=s;
    s->prior = p;
    p->next = s;
    return true;
}
int main(){

}