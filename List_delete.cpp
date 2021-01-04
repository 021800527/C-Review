#include <iostream>
#include <iostream>
using namespace std;
const int MaxSize = 10;
typedef struct {
    int data[MaxSize];
    int length;
}SqList;
bool ListInsert(SqList &L,int i,int e){
    if(i<1||i>L.length+1)
        return false;
    if(L.length>=MaxSize)
        return false;
    for (int j = L.length; j >= i; j--) {
        L.data[j] = L.data[j-1];
    }
    L.data[i-1] = e;
    L.length++;
    return true;
}
bool ListDelete(SqList &L,int i , int &e){
    if(i<1||i>L.length)
        return false;
    e = L.data[i-1];
    for (int j = i; j <L.length ; j++) {
        L.data[j-1]=L.data[j];
    }
    L.length--;
}
int main(){
    SqList L;
    int e = -1;
    if(ListDelete(L,3,e))
        printf("��ɾ����3��Ԫ�أ�ɾ��Ԫ��Ϊ=%d\n",e);
    else
        printf("λ��i���Ϸ���ɾ��ʧ��\n");
    return  0 ;
}