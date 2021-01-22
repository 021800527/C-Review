/*
 * 从有序顺序表中删除所有其值重复的元素，使表中所有元素的值均不同
 */
#include <iostream>
using namespace std;
typedef struct{
    int data[10];
    int length;
}Sqlist;
void Del(Sqlist &L){
    int k = 0;
    for (int i = 1; i < L.length; ++i) {
        if (L.data[i]!=L.data[i-1])
            L.data[i-k] =L.data[i];
        else
            k++;
    }
    L.length = L.length - k;
}
int main(){
    Sqlist L;
    L.length = 10;
    L.data[0] = 1;
    L.data[1] = 2;
    L.data[2] = 2;
    L.data[3] = 2;
    L.data[4] = 2;
    L.data[5] = 3;
    L.data[6] = 3;
    L.data[7] = 4;
    L.data[8] = 4;
    L.data[9] = 5;
    Del(L);
    for (int i = 0; i < L.length; ++i) {
        cout<<L.data[i]<<endl;
    }
}