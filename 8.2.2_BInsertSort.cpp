#include<iostream>
#define MAXSIZE 100
using namespace std;
typedef struct ElemType{
    int key;
};
void BInsertSort(ElemType A[],int n){
    int i , j;
    int low,high,mid;
    for ( i = 2; i <=n ; ++i) {
       A[0]=A[i];
       low = 1;
       high = i-1;
       while (low<=high){
           mid = (low + high)/2;
           if (A[mid].key > A[0].key)
               high = mid - 1;
           else
               low = mid + 1;
       }
        for ( j = i-1; j >= high+1 ; j--) {
            A[j+1] = A[j];
            A[high+1] = A[0];
        }
    }
}