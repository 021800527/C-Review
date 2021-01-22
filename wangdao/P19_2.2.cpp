/*
 * 设计一个高效算法，将顺序表L的所有元素逆置，要求算法的空间复杂度为O（1）
 */
#include <iostream>
using namespace std;
typedef struct {
    int length;
    int data[10];
}Sqlitst;
void Reversed(Sqlitst &L)
{
    /*
     * 辅助变量
     */
    int temp;
    for (int i = 0; i < L.length/2; ++i) {
        temp = L.data[i];
        L.data[i] = L.data[L.length-1-i];
        L.data[L.length-1-i] = temp;
    }
}
