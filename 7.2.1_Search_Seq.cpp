#include <iostream>
using namespace std;
typedef struct {
    int *elem;
    int TableLen;
}SSTable;

int Search_Seq(SSTable ST,int key){
    ST.elem[0] = key;
    for (int i = ST.TableLen; ST.elem[i]!=key ; i--) {
        return i;
    }
}

int main(){
    SSTable nb;
    int a[3];
    a[2] = 1232;
    nb.elem = a;
    cout<<nb.elem[2];
}