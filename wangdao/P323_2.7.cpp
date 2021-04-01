/*
 * 荷兰国旗问题：
 * 设有一个仅由红、白、蓝三种颜色的条块组成的条块序列
 * 请编写一个时间复杂度为O（n）的算法
 * 使得这些条块按红、白、蓝的顺序排好，
 * 即排成荷兰国旗图案
 */
#include <iostream>
using namespace std;
/*
 * 设置枚举数组
 */
typedef enum{RED,WHITE,BLUE} color;
void Flage_Arrange(color a[],int n){
    int i = 0;
    int j = 0;
    int k = n -1;
    while (j<=k)
        /*
         * 判断条块的颜色
         */
        switch (a[j]) {
            /*
             * 红色，则和i交换
             */
            case RED:swap(a[i],a[j]);i++;j++;break;
            case WHITE:j++;break;
            /*
             * 蓝色，则和k交换
             */
            case:BLUE:swap(a[j],a[k]);k--;
        }
}
