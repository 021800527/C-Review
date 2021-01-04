#include <iostream>
#include <stdlib.h>
using namespace std;
typedef struct LNode{
    int data;
    struct LNode *next;
}*LinkList,LNode;
bool ListInsert(LinkList &L,int i , int e){
    if(i<1)
        return false;
    LNode *p;
    int j = 0;
    p = L;
    while(p!=NULL&&j<i-1){
        p = p->next;
        j++;
    }
    if(p==NULL)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}
bool InsertNextNode(LNode *p,int e){
    if(p==NULL)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if(s==NULL)
        return false;
    s->data = e ;
    s->next = p ->next;
    p->next = s;
    return true;
}
bool InsertPriorNode(LNode *p,int e){
    if(p ==NULL)
        return false;

}
int main(){

}