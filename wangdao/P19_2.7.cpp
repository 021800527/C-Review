/*
 * 将两个有序顺序表合并为一个新的有序顺序表，并由函数返回结果顺序表
 */
#include <iostream>
using namespace std;
typedef struct {
    int data[10];
    int length;
    int maxSize;
}Seqlist;
/*
 * 将有序顺序表A和B合并为一个新的有序顺序表C
 */
bool Merge(Seqlist A ,Seqlist B ,Seqlist &C)
{
    /*
     * 将有序顺序表A与B合并为一个新的有序顺序表C
     */
    /*
     * 大于顺序表的最大长度
     */
    if (A.length+B.length>C.maxSize)
        return false;
    int i = 0 , j =0 , k=0;
    /*
     * 循环，两两比较，小者存入结果表
     */
    while (i<A.length&&j<B.length){
        if (A.data[i]<=B.data[j])
            C.data[k++] = A.data[i++];
        else
            C.data[k++] = B.data[j++];
    }
    /*
     * 还剩一个没有比较完的顺序表
     */
    while (i<A.length)
        C.data[k++] = A.data[i++];
    while (j<B.length)
        C.data[k++] = B.data[j++];
    C.length = k;
    return true;
}
int main(){

}