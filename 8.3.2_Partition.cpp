#include<iostream>
#define MAXSIZE 100
using namespace std;
typedef struct ElemType{
    int key;
};
int Partitiom(ElemType A[],int low,int high){
    ElemType pivot = A[low];
    while(low<high){
        while (low<high && A[high].key>=pivot.key)
            high --;
        A[low] = A[high];
        while (low<high && A[low].key<=pivot.key)
            low ++;
        A[high] = A[low];
    }
    A[low] = pivot;
    return low;
}
void QuickSort(ElemType A[],int low,int high){
    if (low<high){
        int pivotpos = Partitiom(A,low,high);
        QuickSort(A,low,pivotpos-1);
        QuickSort(A,pivotpos+1,high);
    }
}