#include <iostream>
using namespace std;
int func2(int x){
    int m,n;
    m = x+1;
    n = x+2;
    return 0;
}
int func1(int a ,int b){
    int x = a+b;
    func2(x);
    x = x + 10086;
    return 0;
}
int factorial (int n){
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n-1);
}
int Fib(int n){
    if (n ==0)
        return 0;
    else if (n==1)
        return 1;
    else
        return Fib(n-1)+Fib(n-2);
}
int main(){
    int x = Fib(4);
    cout<<x;
    return 0;
}