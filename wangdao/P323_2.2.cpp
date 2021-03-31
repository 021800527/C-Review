/*
 * 编写双向冒泡排序算法，在正反两个方向交替进行扫描
 * 即第一趟把关键字最大的元素放在序列的最后面
 * 第二趟把关键字最小的元素放在序列的最前面
 * 如此反复进行
 */
#include <iostream>
using namespace std;
/*
 * 双向起泡排序，交替进行正反两个方向的起泡过程
 */
void BubbleSort(int a[],int n){
    int low = 0;
    int high = n-1;
    int i ;
    /*
     * 一趟起泡后记录元素是否交换标志
     */
    bool flag = true;
    /*
     * 循环跳出条件，当flag为false说明已没有逆序
     */
    while (low<high&&flag){
        /*
         * 每趟初始置flag为false
         */
        flag = false;
        /*
         * 从前向后起泡
         */
        for (i = low; i <high ; ++i) {
            /*
             * 发生逆序
             */
            if (a[i] > a[i + 1]) {
                /*
                 * 交换
                 */
                swap(a[i], a[i + 1]);
                /*
                 * 置flag
                 */
                flag = true;
            }
        }
            /*
             * 更新上界
             */
            high--;
            /*
             * 从后往前起泡
             */
            for (  i = high;  i>low ; i--) {
                /*
                 * 发生逆序
                 */
                if(a[i]<a[i-1]){
                    /*
                     * 交换
                     */
                    swap(a[i],a[i-1]);
                    /*
                     * 置flag;
                     */
                    flag = true;
                }
            }
            /*
             * 修改下界
             */
            low--;
        }
    }