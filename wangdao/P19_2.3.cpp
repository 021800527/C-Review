/*
 * 对长度为n的顺序表L，编写一个时间复杂度为O（n）、空间复杂度为O（1）的算法
 * 该算法删除线性表中所有值为x的数据元素
 */
/*
 /* 解法一：用k记录顺序表L中不等于x的元素个数（即需要保存的元素个数），边扫描L边统计k
 * 并讲不等于x的元素向前移动k个位置，最后修改L的长度
 */
#include <iostream>
using namespace std;
typedef struct {
    int length;
    int data[10];
}Sqlitst;
void del_x_1(Sqlitst &L,int x){
    /*
     * 本算法实现删除顺序表L中所有值为x的数据元素
     */
    int k = 0;
    /*
     * 记录值不等于x的元素个数
     */
    for (int i = 0; i < L.length; ++i) {
        if (L.data[i]!=x)
        {
            L.data[k] = L.data[i];
            /*
             * 不等于x的元素增1
             */
            k++;
        }
    }
    L.length = k;
}
/*
 * 解法二：用K记录顺序表L中等于x的元素个数，边扫描L边统计k，并将不等于x的元素前移k个位置，最后修改L的长度
 */
void del_x_2(Sqlitst &L,int x){
    /*
     * k记录值等于x的元素个数
     */
    int k = 0,i = 0;
    while(i<L.length)
    {
        if (L.data[i]==x)
            k++;
        else
            /*
             * 当前元素前移k个位置
             */
            L.data[i-k] =L.data[i];
            i++;
    }
    L.length = L.length-k;
}
/*
 * 此外，本题还可以考虑头、尾两个指针（i = 0,j = n）,从两端向中间移动，凡遇到最左端值x的元素时，直接将最右端非x的元素左移至值为x的数据元素位置
 * 直到两指针相遇。但这种方法会改变原表中元素的相对位置。
 */