/*
 * 从顺序表中删除具有最小值的元素（假设唯一）并由函数返回被删元素的值。空出的位置由最后一个元素填补，若顺序表为空则显示出错误信息并退出运行
 */
#include <iostream>
using namespace std;
typedef struct {
    int data[10];
    int length;
}sqList;
bool Del_Min(sqList &L,int &value){
    /*
     * 删除顺序表L中的最小值元素结点，并通过饮用型参数value返回其值
     * 若删除成功，则返回true，否则返回false
     */
    /*
     * 表空，终止操作返回
     */
    if(L.length==0)
        return false;
    value = L.data[0];
    /*
     * 假定0号元素的值最小
     */
    int pos = 0;
    /*
     * 循环，寻找具有最小值的元素
     */
    for (int i = 0; i < L.length; ++i) {
        /*
         * 让value记忆当前具有最小值的元素
         */
        if (L.data[i]<value){
            value = L.data[i];
            pos = i;
        }
        /*
         * 空出的位置由最后一个元素填补
         */
        L.data[pos] = L.data[L.length-1];
        L.length--;
        /*
         * 此时value就是最小值
         */
        return true;
    }
}