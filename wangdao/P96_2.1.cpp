/*
 * 假设一个算数表达式中包含圆括号、方括号和花括号3种类型的括号
 * 编写一个算法 来判别表达式中的括号是否配对
 * 以字符"\0"作为算数表达式的结束符
 */
#include <iostream>
#include <stack>
using namespace std;
bool BracketsCheck(char *str){
    /*
     * 初始化栈
     */
    stack<char>S;
    int i = 0;
    while (str[i]!='\0'){
        switch (str[i]) {
            /*
             * 左括号入栈
             */
            case '(':S.push('(');break;
            case '[':S.push('[');break;
            case '{':S.push('{');break;
            /*
             * 遇到右括号，检测栈项
             */
            case ')':if (S.top() =='(') S.pop(); else return false; ;break;
            case ']':if (S.top() =='[') S.pop(); else return false; ;break;
            case '}':if (S.top() =='{') S.pop(); else return false; ;break;
            default:break;
        }
        i++;
    }
    if (!S.empty()){
        cout<<"括号不匹配"<<endl;
        return false;
    }
    else
    {
        cout<<"括号匹配"<<endl;
        return false;
    }
}