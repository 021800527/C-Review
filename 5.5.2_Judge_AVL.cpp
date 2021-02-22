#include <iostream>
using namespace std;
typedef struct BSTNode{
    int data;
    struct BSTNode *lchild,*rchild;
}BSTNode,*BiTree;
void Judge_AVL(BiTree bt , int &balance , int &h){
    int bl = 0 ,br = 0, hl = 0,hr = 0;
    if (bt == NULL){
        h = 0;
        balance = 1;
    }
    else if (bt ->lchild == NULL && bt -> rchild == NULL){
        h = 1;
        balance = 1;
    }
    else
    {
        Judge_AVL(bt->lchild,bl,hl);
        Judge_AVL(bt->rchild,br,hr);
        if (hl > hr)
            h = hl + 1;
        else
            h = hr + 1;
        if (abs(hl-hr)< 2&&bl == 1&&br == 1)
            balance = 1;
        else
            balance = 0;
    }
}