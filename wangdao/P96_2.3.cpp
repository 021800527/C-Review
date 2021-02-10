/*
 * 利用一个栈实现以下递归函数的非递归运算
 * P(x) = 1(n = 0)
 * P(x) = 2x (n=1)
 * Pn(x) = 2xPn-1(x) - 2(n-1)Pn-2(x) (n>1)
 */
/*
 * 设置一个栈用于保存n和对应的pn（x）值，栈中相邻元素的Pn（x）值，栈中相邻元素的Pn（x）有题中关系。
 * 然后边出栈边计算Pn（x），栈空后该值就计算出来了。算法的实现如下
 */
#include <iostream>
#include <stack>
using namespace std;
#define MaxSize 10
double p(int n , double x){
    struct stack{
        /*
         * 保存n
         */
        int no;
        /*
         * 保存Pn（x）值
         */
        double val;
    }st[MaxSize];
    /*
     * top为栈st的下标值变量
     */
    int top = -1,i;
    /*
     * n = 0, n = 1 时的初值
     */
    double fv1 = 1 ,fv2 = 2 * x;
    for ( i = n; i >=2 ; i--) {
        top++;
        st[top].no = i;
    }
    /*
     * 入栈
     */
    while (top>=0){
        st[top].val = 2 * x * fv2 - 2 * (st[top].no - 1) * fv1;
        fv1 = fv2;
        fv2 = st[top].val;
        top -- ;
    }
    /*
     * 出栈
     */
    if (n==0)
        return fv1;
    return fv2;
}