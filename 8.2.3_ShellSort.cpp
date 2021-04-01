#include<iostream>
#define MAXSIZE 100
using namespace std;
typedef struct ElemType{
    int key;
};
void ShellSort(ElemType A[],int n){
    int j ;
    for (int dk = n/2 ; dk >= 1; dk = dk/2) {
        for (int i = dk+1; i <= n; ++i) {
            if (A[i].key<A[i-dk].key){
                A[0] = A[i];
                for (j = i-dk; j > 0&& A[0].key< A[j].key; j-=dk) {
                    A[j+dk] = A[j];
                }
                A[j+dk]=A[j];
            }
        }
    }
}