/*
 * 题目描述
给出两个序列 pushed 和 poped 两个序列，其取值从 1 到 n(n\le100000)n(n≤100000)。已知入栈序列是 pushed，如果出栈序列有可能是 poped，则输出 Yes，否则输出 No。为了防止骗分，每个测试点有多组数据。

输入格式
第一行一个整数 qq，询问次数。

接下来 qq 个询问，对于每个询问：

第一行一个整数 nn 表示序列长度；

第二行 nn 个整数表示入栈序列；

第二行 nn 个整数表示出栈序列；

输出格式
对于每个询问输出答案。


 */
#include<iostream>
#include<stack>
using namespace std;
stack<int>q;//栈q
int p,n;//p组数据，n为序列长度
int main()
{
    cin>>p;
    while(p--)
    {
        cin>>n;
        int a[n+1],b[n+1],sum=1;//入栈队列a，待检验队列b，计数器sum
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=n;i++)
            cin>>b[i];//平平无奇的输入
        for(int i=1;i<=n;i++)
        {
            q.push(a[i]);//入栈
            while((q.top())==b[sum])//当栈顶元素与b中当前元素相同时出栈
            {
                q.pop();
                sum++;//sum++到b下一个元素
                if(q.empty())break;//注意这里，第一次RE就因为当栈空时还用了出栈操作，所以要手动结束循环
            }
        }
        if(q.empty()) cout<<"Yes"<<endl;//如果栈为空说明出栈序列b正确
        else cout<<"No"<<endl;
        while(!q.empty())q.pop();//清空栈
    }
    return 0;//谢幕
}