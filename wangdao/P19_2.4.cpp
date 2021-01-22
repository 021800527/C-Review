#include <iostream>
using namespace std;
typedef struct {
    int length;
    int data[10];
}Sqlitst;
/*
 * 从有序顺序表中删除其值在给定值s与t之间（要求s<t）的所有元素，如果s或t不合理或顺序为空，则显示出错信息并退出运行
 */
/*
 * 本体与上一题的区别。因为是有序表，所以删除的元素必然是相连的整体。
 * 算法思想：先寻找值大于等于s的第一个元素（第一个删除的元素），然后寻找值大于t的第一个元素（最后一个删除的元素的下一个元素），
 * 要将这段元素删除，只需直接将后面的元素前移
 */
bool Del_s_t2(Sqlitst &L ,int s ,int t){
    /*
     * 删除有序顺序表L中值在给定值s与t质之间的所有元素
     */
    int i,j;
    if (s>=t||L.length==0)
        return false;
    /*
     * 寻找值大于等于s的第一个元素
     */
    for (i = 0; i < L.length&&L.data[i]<s; ++i)
        /*
         * 所有元素值均小于s，返回
         */
        if (i>=L.length)
            return false;
        /*
         * 寻找值大于t的第一个元素
         */
        for (j = i;  j <L.length&&L.data[j]<=t ; j++) ;
        /*
         * 前移，填补被删元素位置
         */
        for(;j<L.length;i++,j++)
            L.data[i]=L.data[j];
        L.length = i;
        return true;
}