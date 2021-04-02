#include<iostream>
using namespace std;
void SelectSort(int A[],int n){
    int j;
    for (int i = 0; i < n-1; ++i) {
        int min = i;
        for (j = i+1; j < n; ++j) {
            if (A[j]<A[min])
                min = j;
        }
        if (min = j)
            swap(A[i],A[min]);
    }
}