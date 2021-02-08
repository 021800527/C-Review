#include <iostream>
using namespace std;
/*
 * 判断字符数组A中的输入输出序列是否是合法序列。如果是，返回true，否则返回false
 */
int Judge(char A[]){
    /*
     * i为下标，j和k分别为字母I和O的个数
     */
    int i = 0;
    int j =0,k = 0 ;
    /*
     * 未到字符数组尾
     */
    while (A[i]!='\0'){
        switch (A[i]) {
            /*
             * 入栈次数增1
             */
            case 'I':j++;break;
            case 'O':k++;
                if (k>j){
                    cout<<"序列非法"<<endl;
                    exit(0);
                }
        }
        /*
         * 不论A【i】是“I”或“O”，指针i均后移
         */
        i++;
    }
    if (j!=k) {
        cout << "非法序列" << endl;
        return false;
    }
    else
    {
        cout<<"序列合法"<<endl;
        return true;
    }
}