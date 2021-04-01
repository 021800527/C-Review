#include <iostream>
using namespace std;
int setPartition(int a[],int n ) {
    int pivotkey;
    int low;
    int low0 = 0;
    int high = n - 1;
    int high0 = n - 1;
    int flag = 1;
    int k = n / 2;
    int s1 = 0;
    int s2 = 0;
    while (flag) {
        /*
         * 选择枢轴
         */
        pivotkey = a[low];
        /*
         * 基于枢轴对数据进行划分
         */
        while (low < high) {
            while (low < high && a[high] >= pivotkey) --high;
            if (low != high) a[low] = a[high];
            while (low < high && a[low] <= pivotkey) ++low;
            if (low != high) a[high] = a[low];
        }
        a[low] = pivotkey;
        /*
         * 若枢轴是第n/2小元素，划分成功
         */
        if (low = k - 1)
            flag = 0;
        /*
         * 是否继续划分
         */
        else
        {
            if (low<k-1){
                low0=++low;
                high = high0;
            }
            else
            {
                high = --high;
                low = low0;
            }
        }
    }
    for (int i= 0;  i< k; i++) {
        s1+=a[i];
    }
    for (int i = k; i < n; ++i) {
        s2+=a[i];
    }
    return s2-s1;
}