#include<iostream>
#define MAXSIZE 100
using namespace std;
typedef struct ElemType{
    int key;
};
void BubbleSort(ElemType A[],int n){
    for (int i = 0; i < n-1; ++i) {
        bool flag = false;
        for (int j = n-1; j > i  ; j--) {
            if (A[j-1].key>A[j]){
                swap(A[j-1],A[j]);
                flag = true;
            }
        if (flag==false)
            return;
        }
    }
}