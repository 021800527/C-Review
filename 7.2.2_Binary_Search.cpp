#include <iostream>
using namespace std;
typedef struct {
    int *elem;
    int TableLen;
}SeqList;
int Binary_Search(SeqList L,int key){
    int low = 0;
    int high = L.TableLen-1;
    int mid;
    while (low<=high)
    {
        mid = (low+high)/2;
        if(L.elem[mid]==key)
            return mid;
        else if (L.elem[mid]>key)
            high = mid - 1;
        else
            low = mid +1;
    }
    return -1;
}