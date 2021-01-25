/*
 * 链接：https://www.nowcoder.com/questionTerminal/a62616543c5f483fb98cee66b37faaad?orderByHotValue=1&mutiTagIds=597&page=1&onlyReference=false
来源：牛客网

一个长度为L（L≥1）的升序序列S，处在第 ëL/2ù 个位置的数称为S的中位数。例如，若序列S1=（11，13，15，17，19），则S1的中位数是15，两个序列的中位数是含它们所有元素的升序序列的中位数。例如，若S2=（2，4，6，8，20），则S1和S2的中位数是11。现在有两个等长升序序列A和B，试设计一个在时间和空间两方面都尽可能高效的算法，找出两个序列A和B的中位数。要求：

（1）给出算法的基本设计思想。

（2）根据设计思想，采用C、C++或Java语言描述算法，关键之处给出注释。

（3）说明你所设计算法的时间复杂度和空间复杂度。
 */
/*
 * 分别求两个升序序列A、B的中位数，设为a和b，求序列A、B的中位数过程如下：
 * 1、若a=b，则a或b即为所求中位数，算法结束
 * 2、若a<b,则舍弃序列A中较小的一半，同时舍弃序列B中较大的一半，要求两次舍弃的长度相等。
 * 3、若a>b，则舍弃序列A中较大的一半，同时舍弃序列B中较小的一半，要求两次舍弃的长度相等
 * 在保留的升序序列中，重复过程1，2，3，直到两个序列中均只含有一个元素时为止，较小者即为所求的中位数
 */
#include <iostream>
using namespace std;
int M_Search(int A[],int B[],int n){
    /*
     * 分别表示序列A和B的首位数、末尾数和中位数
     */
    int s1 = 0,d1 = n-1,m1,s2 = 0,d2 = n-1,m2;
    while (s1!=d1||s2!=d2){
        m1 = (s1+d1)/2;
        m2 = (s2+d2)/2;
        /*
         * 满足条件1
         */
        if(A[m1]==B[m2])
            return A[m1];
        /*
         * 满足条件2
         */
        if (A[m1]<B[m2])
        {
            /*
             * 若元素个数为奇数
             */
            if ((s1+d1)%2==0)
            {
                s1 = m1;/*舍弃A中间点以前的部分且保留中间点*/
                d2 = m2;/*舍弃B中间点以后的部分且保留中间点 */
            }
            /*
             * 元素个数为偶数
             */
            else
            {
                s1 = m1+1;/* 舍弃A中间点及中间点以前部分 */
                d2 = m2;/* 舍弃B中间点以后部分且保留中间点 */
            }

        }
        /*
         * 满足条件3
         */
        else{
            /*
             * 若元素个数为奇数
             */
            if ((s2+d2)%2==0){
                d1 = m1;/* 舍弃A中间点以后部分且保留中间点 */
                s2 = m2;/* 舍弃B中间点及中间点以前部分 */
            }
        }

    }
    return A[s1]<B[s2]?A[s1]:B[s2];
}