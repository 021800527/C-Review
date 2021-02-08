/*
 * 设有两个栈s1和s2都采用顺序栈方式。并共享一个存储区【0,...,maxsize-1】
 * 为了尽量利用空间，减少溢出的可能，可采用栈顶相向、迎面增长的存储方式
 * 试设计s1s2有关入栈和出栈的操作算法
 */
/*
 * 入栈操作。i为栈号，i=0表示左边的s1栈，i=1表示右边的栈
 * x是入栈元素
 * 入栈成功返回1，否则返回0
 */
#include <iostream>
using namespace std;
int push(int i ,int x){
if(i <0 || i>1){
    cout<<"栈号输入不对"<<endl;
    exit(0);
}
/*
 * 入栈操作
 */
if (s.top[i]-s.top[0]==1){
    cout<<"栈已满"<<endl;
    return 0;
    switch (i) {
        case 0:s.stack[++s.top[0]] = x;
            return 1;
            break;;
        case 1:s.stack[--s.top[1]] = x;
        return 1;
    }
}
}
/*
 * 退栈操作
 */
int pop(int i ){
    /*
     * 退栈算法。i代表栈号，i=0时为s1栈，i=1时为s2栈
     * 退栈成功返回退栈元素，否则返回-1
     */
    if (i<0||i>1){
        cout<<"栈号输入错误"<<endl;
        exit(0);
    }
    switch (i) {
        case 0:
            if (s.top[0]==-1){
                cout<<"栈空"<<endl;
                return -1;
            }
            else
                return s.stack[s.top[0]--];
        case 1:
            if (s.top[1]==maxsize){
                cout<<"栈空"<<endl;
                return -1;
            } else{
                return s.stack[s.top[1]++];
            }
    }
}
