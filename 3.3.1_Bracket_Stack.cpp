#include <iostream>
using namespace std;
/*
 *定义栈中元素的最大个数
 */
#define MaxSize 10
typedef struct {
    /*
     * 静态数组存放栈中元素
     */
    char data[MaxSize];
    /*
     * 栈顶指针
     */
    int top;
}SqStack;
/*
 * 初始化栈
 */
void InitStack(SqStack &S);
/*
 * 判断栈是否为空
 */
bool StackEmpty(SqStack &S);
/*
 * 新元素入栈
 */
bool Push(SqStack &S,char x);
/*
 * 栈顶元素出栈，用x返回
 */
bool Pop(SqStack &S,char &x);
bool BracketCheck(char str[],int length){
    SqStack S;
    /*
     * 初始化栈
     */
    InitStack(S);
    for (int i = 0; i < length; ++i) {
        if (str[i]=='('||str[i]=='['||str[i]=='{'){
            /*
             * 扫描到左括号，入栈
             */
            Push(S,str[i]);
        } else{
            /*
             * 扫描到右括号，且当前栈空
             */
            if (StackEmpty(S))
                /*
                 * 匹配失败
                 */
                return false;
            char topElem;
            /*
             * 栈顶元素出栈
             */
            Pop(S,topElem);
            if (str[i]==')'&& topElem!='(')
                return false;
            if (str[i]==']'&& topElem!='[')
                return false;
            if (str[i]=='}' && topElem !='{')
                return false;
        }
    }
    /*
     * 检查完全部括号后，栈空说明匹配成功
     */
    return StackEmpty(S);
}