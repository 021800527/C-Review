#include <iostream>
using namespace std;

#define MAxLEN 255
typedef struct {
    char ch[MAxLEN];
    int length;
}SString;
/*
 * 求模式串的next数组
 */
void get_next(SString T,int next[]){
    int i = 1, j = 0;
    next[1] = 0 ;
    while (i<T.length){
        if (j == 0 || T.ch[i]==T.ch[j]){
            ++i;
            ++j;
            /*
             * 若pi = pj ， 则 next[j+1] = next[j] + 1
             */
            next[i] = j;
        } else
            /*
             * 否则令 j = next[j],循环继续
             */
            j = next[j];
    }
}
/*
 * KMP算法
 */
int Index_KMP(SString S ,SString T){
    int i = 1, j = 1;
    int next[T.length+1];
    /*
     * 求模式串的next数组
     */
    get_next(T,next);
    while (i<=S.length && j <= T.length){
        if (j == 0 || S.ch[i] == T.ch[j]){
            ++i;
            ++j;
            /*
             * 继续比较后续字符
             */
        } else
            j = next[j];
    }
    if (j>T.length)
        /*
         * 匹配成功
         */
        return i - T.length;
    else
        return 0;
}