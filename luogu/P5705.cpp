#include <iostream>
using namespace std;
int main(){
    float a ;
    cin >> a;
    a = a*10;
    int b[4];
    int d;
    d = 1000;
    for (int i = 0; i < 4; ++i) {
        b[i] = a/d;
        a = a - d*b[i];
        d = d/10;
    }
    d = 1000;
    float res;
    res = 0;
    for (int i = 3; i >= 0; i--) {
        res = res + b[i]*d;
        d = d/10;
    }
    cout<<res/1000;
}