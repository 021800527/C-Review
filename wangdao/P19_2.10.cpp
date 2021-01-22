/*
 * 设将n(n,1)个整数存放到一维数组R中，试设计一个在时间和空间两方面尽可能有效的算法，将R中保有的序列循环左移P（0﹤P﹤n）个位置，即将R中的数据由（X0 X1 ……Xn-1）变换为（Xp Xp+1 ……Xn-1 X0 X1 ……Xp-1）要求：

　　（1）给出算法的基本设计思想。

　　（2）根据设计思想，采用C或C++或JAVA语言表述算法，关键之处给出注释。

　　（3）说明你所设计算法的时间复杂度和空间复杂度
 */
#include <iostream>
using namespace std;
typedef struct {
    int data[10];
    int length;
    int maxSize;
}Seqlist;
bool Reverse(int R[],int from,int to){
    int i ,temp;
    for ( i = 0; i <(to-from+1)/2 ; ++i) {
        temp = R[from +i];
        R[from+i] = R[to-i];
        R[to-i] = temp;
    }
}
void Converse(int R[],int n ,int p){
    Reverse(R,0,p-1);
    Reverse(R,p,n-1);
    Reverse(R,0,n-1);
}