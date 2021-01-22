/*
 * 已知在一维数组A[m+n]中依次存放两个线性表(a1,a2,a3,...am)和(b1,b2,b3,...,bn)，试编写一个函数，
 * 将两个数组中两个顺序表的位置互换，即(b1,b2,b3,...,bn)放在(a1,a2,a3,...,am)的前面
 */
#include <iostream>
using namespace std;
void Reverse(int A[],int left,int right,int arraySize){
    /*
     * 逆转（aleft,aleft+1,aleft+2...,aright）为（aright,aright-1,...,aright）
     */
    if (left>=right||right>=arraySize)
        return;
    int mid = (left+right)/2;
    for (int i = 0; i < mid - left; ++i) {
        int temp = A[left+i];
        A[left+i] = A[right-i];
        A[right-i] = temp;
    }
}
void Exchange(int A[],int m,int n,int arraySize){
    /*
     * 数组A[m+n]中，从0到m-1存放顺序表(a1,a2,a3,...,am),从m到m+n-1存放顺序表(b1.b2.b3....,bn),算法将这两个表的位置互换
     */
    Reverse(A,0,m+n-1,arraySize);
    Reverse(A,0,n-1,arraySize);
    Reverse(A,n,m+n-1,arraySize);
}