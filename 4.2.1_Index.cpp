#include <iostream>
using namespace std;

#define MAxLEN 255
typedef struct {
    char ch[MAxLEN];
    int length;
}SString;
int Index(SString S, SString T){
    int k = 1;
    int i = k , j = 1;
    while (i<=S.length && j<= T.length){
        if (S.ch[i]==T.ch[j]){
            /*
             * 继续比较后继字符
             */
            ++i;
            ++j;
        } else{
            /*
             * 检查下一个子串
             */
            k++;
            i = k ;
            j = 1;
        }
    }
    if (j>T.length)
        return k;
    else
        return 0;
}