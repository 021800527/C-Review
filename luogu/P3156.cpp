#include <iostream>
using namespace std;
int main(){
     int a , b;
     cin>>a>>b;
     int num[a];
     for (int i = 0; i < a; ++i) {
        cin>>num[i];
    }
    int x;
    for (int i = 0; i < b; ++i) {
        cin>>x;
        cout<<num[x-1];
        if (i!=(b-1))
            cout<<endl;
    }
}