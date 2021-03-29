#include<iostream>
#define MAXSIZE 100
using namespace std;
typedef struct ElemType{
    int key;
};
void InsertSort(ElemType A[],int n){
    int i ,j;
    for ( i = 0; i < ; ++i) {
        A[0] = A[i];
        for (j = i-1;  A[0].key<A[j].key ;j--) {
            A[j+1] = A[j];
        }
        A[j+1]= A[0]
    }
}