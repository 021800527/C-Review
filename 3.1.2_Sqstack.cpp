#include <stdlib.h>
/*
 * 定义栈中元素的最大个数
 */
#define MaxSize 10
typedef struct {
    /*
     * 静态数组翠芳栈中元素
     */
    int data[MaxSize];
    /*
     * 栈顶指针
     */
    int top;
}SqStack;
/*
 * 初始化栈
 */
void  InitStack(SqStack &S){
    S.top = -1;
}
/*
 * 判断栈空
 */
bool StackEmpty(SqStack S){
    if (S.top==-1)
        return true;
    else
        return false;
}
/*
 * 新元素入栈
 */
bool Push(SqStack &S,int x){
    /*
     * 栈满，报错
     */
    if (S.top==MaxSize-1)
        return false;
    /*
     * 指针先加1
     */
    S.top = S.top+1;
    /*
     * 新元素入栈
     */
    S.data[S.top] = x;
}
/*
 * 出栈操作
 */
bool Pop(SqStack &S,int &x){
    /*
     * 栈空，报错
     */
    if (S.top==-1)
        return false;
    /*
     * 栈顶元素要先出栈
     */
    x = S.data[S.top];
    /*
     * 指针再减1
     */
    S.top = S.top-1;
    return true;
}
/*
 * 读栈顶元素
 */
bool GetTop(SqStack S,int &x){
    /*
     * 栈空，报错
     */
    if (S.top==-1)
        return false;
    x = S.data[S.top];
    return true;
}