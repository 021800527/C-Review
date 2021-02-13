#include <iostream>
using namespace std;
typedef struct ThreadNode{
    int data;
    struct ThreadNode *lchild,*rchild;
    int ltag,rtag;
}ThreadNode,*ThreadTree;
void InThread(ThreadTree &p, ThreadTree &pre){
    if(p!=NULL){
        InThread(p->lchild,pre);
        if (p->lchild == NULL){
            p ->lchild = pre;
            p ->ltag = 1;
        }
        if (pre != NULL && pre->rchild == NULL){
            pre -> rchild = p;
            pre ->rtag = 1;
        }
        pre = p;
        InThread(p->rchild,pre);
    }
}
void CreateInThread(ThreadTree T){
    ThreadTree pre = NULL;
    if (T!=NULL){
        InThread(T,pre);
        pre->rchild = NULL;
        pre -> rtag = 1;
    }
}
ThreadNode *Firstnode(ThreadNode *p){
    while (p->ltag == 0)
        p = p ->lchild;
    return p;
}
ThreadNode *Nextnode(ThreadNode *p){
    if (p -> rtag == 0)
        return Firstnode(p->rchild);
    else
        return p ->rchild;
}
void Inorder(ThreadNode *T){
    for (ThreadNode *p= Firstnode(T); p!=NULL ; p=Nextnode(p)) {
        //visit(p);
    }
}