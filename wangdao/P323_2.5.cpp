#include<iostream>
using namespace std;
int kth_elem(int a[],int low ,int high,int k ){
    int pivot = a[low];
    /*
     * 由于下面会修改low和high，在递归时又要用到它们
     */
    int low_temp = low;
    int high_temp = high;
    while (low<high){
        while (low<high && a[high]>=pivot)
            --high;
        a[low] = a[high];
        while (low<high && a[low]<=pivot)
            ++low;
        a[high] = a[low];
    }
    a[low]=pivot;
    /*
     * 上面即为快速排序中的划分算法
     * 下面就是本算法思想中所述的内容
     */
    /*
     * 由于与k相同，直接返回pivot的值
     */
    if (low==k)
        return a[low];
    /*
     * 在前一部分表递归查找
     */
    else if(low>k)
        return kth_elem(a,low_temp,low-1,k);
    /*
     * 在后一部分表中递归查找
     */
    else
        return kth_elem(a,low+1,high_temp,k);

}