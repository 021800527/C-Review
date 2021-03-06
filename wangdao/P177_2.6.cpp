/*
 * 以孩子兄弟链表为存储结构，请设计递归算法求树的深度
 */
#include <iostream>
using namespace std;
typedef struct node{
    int data;
    struct node *firstchild,*nextsibling;
}*CSTree;
/*
 * 递归求以孩子兄弟链表表示的树的深度
 */
int Height(CSTree bt){
    int hc,hs;
    if (bt == NULL)
        return 0;
    /*
     * 否则，高度取子女高度+1和兄弟子树高度的大者
     */
    else
    {
        /*
         * 第一子女树高
         */
        hc = Height(bt->firstchild);
        /*
         * 兄弟树高
         */
        hs = Height(bt->nextsibling);
        if (hc+1>hs)
            return hc + 1;
        else
            return hs;
    }
}
