#include <stdlib.h>
const int InitSize = 10;
typedef struct {
    int *data;
    int MaxSize;
    int length;
}SeqList;
void InitList(SeqList &L){
    L.data = (int *)malloc(InitSize*sizeof(int));
    L.length = 0;
    L.MaxSize = InitSize;
}
int GetElem(SeqList L,int i){
    return L.data[i-1];
}