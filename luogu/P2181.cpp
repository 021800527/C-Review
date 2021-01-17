/*
 * 题目描述
对于一个 nn 个顶点的凸多边形，它的任何三条对角线都不会交于一点。请求出图形中对角线交点的个数。

例如，66 边形：



输入格式
输入只有一行一个整数 nn，代表边数。

输出格式
输出一行一个整数代表答案。

输入输出样例
输入 #1复制
3
输出 #1复制
0
输入 #2复制
6
输出 #2复制
15
说明/提示
数据规模与约定
对于 50 \%50% 的数据，保证 3 \leq n \leq 1003≤n≤100。
对于 100 \%100% 的数据，保证 3 \leq n \leq 10^53≤n≤10
5
 */
#include <iostream>
using namespace std;
int main(){
    unsigned long long  int ans;
    unsigned long long int  n ;
    cin>>n;
    ans = n * (n-1) / 2 * (n-2) / 3 * (n-3) / 4;
    cout<<ans;
    return 0;
}