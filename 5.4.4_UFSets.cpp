#include <iostream>
using namespace std;
#define SIZE 100
int UFSets[SIZE];
void Initial(int s[]) {
    for (int i = 0; i < SIZE; ++i) {
        s[i] = -1;
    }
}
int Find(int s[], int x){
        while(s[x]>=0)
            x = s[x];
        return x;
}
void Union(int s[],int Root1,int Root2){
    s[Root2] = Root1;
}