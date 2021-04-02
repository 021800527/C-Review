#include <iostream>
using namespace std;
void AdjustDown(int A[],int k ,int len){
    A[0] = A[k];
    for (int i = 2*k; i <= len ; i*=2) {
        if (i<len && A[i]<A[i+1])
            i++;
        if (A[0]>=A[i])
            break;
        else
        {
            A[k] = A[i];
            k = i;
        }
    }
    A[k] = A[0];
}
void BuildMaxHeap(int A[],int len){
    for (int i = len/2; i > 0; i--) {
        AdjustDown(A,i,len);
    }
}
void HeapSort(int A[],int len){
    BuildMaxHeap(A,len);
    for (int i = len; i > 1; i--) {
        swap(A[i],A[1]);
        AdjustDown(A,1,i-1);
    }
}
