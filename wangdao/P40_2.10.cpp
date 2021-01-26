/*
 * 将一个带头结点的单链表A分解为两个带头结点的单链表A和B，使得A表中含有原表中序号为奇数的元素
 * 而B表中含有原表中序号为偶数的元素，且保持其相对顺序不变
 */
#include <iostream>
using namespace std;
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;
/*
 * 将表A中结点按序号的奇偶性分解到表A或表B中
 */
LinkList DisCreat_1(LinkList &A){
    /*
    * i记录表a中结点的序号
    */
    int i = 0;
    /*
     * 创建B表表头
    */
    LNode *B =new LNode();
    /*
     * B表的初始化
     */
    B->next = NULL;
    /*
     * ra和rb分别指向将创建的A表和B表的尾结点
     */
    LNode *ra = A;
    LNode *rb = B;
    /*
     * p为链表工作指针，指向待分解的结点
     */
    LNode *p = A->next;
    /*
     * 置空新的A表
     */
    A->next = NULL;
    while (p!=NULL){
        /*
         * 序号加1
         */
        i++;
        /*
         * 处理序号为偶数的链表结点
         */
        if (i%2==0){
            /*
             * 在B表尾插入新结点
             */
            rb ->next = p;
            /*
             * rb指向新的尾结点
             */
            rb = p;
        } else
        {
            /*
             * 处理原序号为奇数的结点
             */
            ra ->next = p;
            /*
             * 在A表尾插入新的结点
             */
            ra =p;
        }
        /*
         * 将p恢复为指向新的待处理结点
         */
        p = p->next;
    }
    ra ->next =NULL;
    rb ->next =NULL;
    return B,A;
}