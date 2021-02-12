/*
 * 根据 逆波兰表示法，求表达式的值。

有效的运算符包括 +, -, *, / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。

 

说明：

整数除法只保留整数部分。
给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。

 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> v;
        for( auto s : tokens )
        {
            if( s == "+" || s == "-" || s == "*" || s == "/" )
            {
                int second  = v.back(); v.pop_back();
                int first   = v.back(); v.pop_back();
                if( s == "+" ){ v.push_back( first + second ); }
                if( s == "-" ){ v.push_back( first - second ); }
                if( s == "*" ){ v.push_back( first * second ); }
                if( s == "/" ){ v.push_back( first / second ); }
            }
            else
            {
                v.push_back( stoi(s) );
            }
        }
        return v.back();
    }
};