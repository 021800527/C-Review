/*
 * 从顺序表中删除其值在给定值s与t之间（包含s和t，要求s<t）的所有元素，如果s或t不合理或顺序表为空，则显示错误信息并退出运行
 */
typedef struct {
    int data[10];
    int length;
}Sqlist;
#include <iostream>
using namespace std;
bool Del_s_t(Sqlist &L,int s ,int t){
    /*
     * 不合法直接返回
     */
    if(t>=L.length||L.length==0)
        return false;
    /*
     * 辅助变量
     */
    int k ;
    k= 0;
    for (int i = 0; i < L.length; ++i) {
        if (L.data[i]>=s&&L.data[i]<=t)
        {
            k++;
        }
        else
            L.data[i-k]=L.data[i];
    }
    L.length = L.length-k;
    return true;
}