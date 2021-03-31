/*
 *已知线性表按顺序存储，且每个元素都是不相同的整型元素
 * 设计把所有奇数移动到所有偶数前边的算法
 * 要求时间最少，辅助空间最少
 */
#include <iostream>
using namespace std;
/*
 * 对表A按奇偶进行一趟划分
 */
void move(int A[],int len){
    /*
     * i表示左端偶数元素的下标，j表示右端奇数元素的下标
     */
    int i = 0;
    int j = len - 1;
    while(i<j){
        /*
         * 从前向后找到一个偶数元素
         */
        while (i<j&&A[i]%2!=0) i++;
        /*
         * 从后向前找到一个奇数元素
         */
        while (i<j&&A[i]%2!=1) j--;
        if (i<j){
            /*
             * 交换这两个元素
             */
            swap(A[i],A[j]);
            i++;
            j--;
        }
    }
}