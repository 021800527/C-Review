/*
 *  试重新编写考点精析中的快速排序的划分算法
 *  使之每次选取的枢轴值都是随机地从当前子表中选择的
 */
#include <iostream>
using namespace std;
int Partition(int A[],int low,int high){
    int rand_Index = low +rand()%(high - low + 1);
    /*
     * 将枢轴值交换到第一个元素
     */
    swap(A[rand_Index],A[low]);
    /*
     * 置当前表中的第一个元素为枢轴值
     */
    int pivot = A[low];
    /*
     * 使得表A中的所有元素小于pivot，初始为空表
     */
    int i = low;
    /*
     * 从第二个元素开始寻找小于基准的元素
     */
    for (int j = low+1; j <=high ; ++j) {
        /*
         * 找到后，交换到前面
         */
        if(A[j]<pivot)
            swap(A[++i],A[j]);
    /*
     * 将基准元素插入到最终位置
     */
    swap(A[i],A[low]);
    /*
     * 返回基准元素的位置
     */
    return i ;
    }
}