/*
 * 已知一棵树的层次序列及每个节点的度，编写算法构造此树的孩子-兄弟链表
 */
#include <iostream>
#define MaxSize 15
using namespace std;
typedef struct CSNode{
    int data;
    struct CSNode *firstchild,*nextsibling;
}*CSTree,CSNode;
/*
 * 根据树结点的层次序列e[]和各结点的度drgree[]构造树的孩子-兄弟链表
 * 参数n是树结点个数
 */
void createCSTree_Degree(CSTree &T,int e[],int degree[],int n){
    /*
     * 判断pointer[i]为空的语句未写
     */
    CSNode *pointer = new CSNode [MaxSize];
    int i,j,d,k = 0;
    /*
     * 初始化
     */
    for ( i = 0; i < n; ++i) {
        pointer[i].data = e[i];
        pointer[i].firstchild = pointer[i].nextsibling = NULL;
    }
    for (i = 0; i < n; ++i) {
        /*
        * 结点i的度数
        */
        d = degree[i];
        if (d){
            /*
             * k为子女结点序号
             */
            k++;
            /*
             * 建立i与子女k间的链接
             */
            pointer[i].firstchild = &pointer[k];
            for ( j = 2; j <= d; ++j) {
                k++;
                pointer[k-1].nextsibling = &pointer[k];
            }
        }
    }
    T = &pointer[0];
    delete []pointer;
}