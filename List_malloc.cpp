#include <iostream>
#include <stdlib.h>
using namespace std;
int InitSize = 10;
typedef struct{
    int *data;
    int MaxSize;
    int length;
}SeqList;
void list(SeqList &L){
    L.data = (int *)malloc(InitSize*sizeof(int));/* 用malloc 函数申请一片连续的存储空间*/
    L.length = 0;
    L.MaxSize = InitSize;
}
void IncreaseSize(SeqList &L , int len){
    int *p = L.data;
    L.data = (int *)malloc((len+L.MaxSize)*sizeof(int));
    for (int i = 0; i < L.length; i++) {
        L.data[i] = p[i];
    }
    L.MaxSize = L.MaxSize+len;
    free(p);
}
int main() {
    SeqList L;
    list(L);
    IncreaseSize(L,5);
    return 0;
}
