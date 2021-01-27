/*
 * 题目背景
模板题，无背景。

2019.12.12 更新数据，放宽时限，现在不再卡常了。

题目描述
给出项数为 nn 的整数数列 a_{1 \dots n}a
1…n
​
 。

定义函数 f(i)f(i) 代表数列中第 ii 个元素之后第一个大于 a_ia
i
​
  的元素的下标，即 f(i)=\min_{i<j\leq n, a_j > a_i} \{j\}f(i)=min
i<j≤n,a
j
​
 >a
i
​

​
 {j}。若不存在，则 f(i)=0f(i)=0。

试求出 f(1\dots n)f(1…n)。

输入格式
第一行一个正整数 nn。

第二行 nn 个正整数 a_{1\dots n}a
1…n
​
 。

输出格式
一行 nn 个整数 f(1\dots n)f(1…n) 的值。

输入输出样例
输入 #1复制
5
1 4 2 3 5
输出 #1复制
2 5 4 5 0
说明/提示
【数据规模与约定】

对于 30\%30% 的数据，n\leq 100n≤100；

对于 60\%60% 的数据，n\leq 5 \times 10^3n≤5×10
3
  ；

对于 100\%100% 的数据，1 \le n\leq 3\times 10^61≤n≤3×10
6
 ，1\leq a_i\leq 10^91≤a
i
​
 ≤10
9
 。
 */
#include<iostream>
#include<stack>
using namespace std;
int n,a[3000005],f[3000005];//a是需要判断的数组（即输入的数组），f是存储答案的数组
stack<int>s;//模拟用的栈
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=n;i>=1;i--)
    {
        while(!s.empty()&&a[s.top()]<=a[i]) s.pop();//弹出栈顶比当前数小的
        f[i]=s.empty()?0:s.top();//存储答案，由于没有比她大的要输出0，所以加了个三目运算
        s.push(i);//压入当前元素
    }
    for(int i=1;i<=n;i++) printf("%d ",f[i]);//输出
    return 0;
}