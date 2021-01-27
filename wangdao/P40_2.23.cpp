/*
 * 用单链表保存m个整数，结点的结构为： ，且|data|≤n(n为正整数)。现要求设计一个时间复杂度尽可能高效的算法，
 * 对于链表中data的绝对值相等的结点，仅保留第一次出现的结点而删除其余绝对值相等的结点。例如，若给定的单链表head如下：
    (1)给出算法的基本设计思想。
    (2)使用C或C++语言，给出单链表结点的数据类型定义。
    (3)根据设计思想，采用C或C++语言描述算法，关键之处给出注释。
    (4)说明你所设计算法的时间复杂度和空间复杂度。
 */
#include <iostream>
using namespace std;
typedef struct LNode{
    int data;
    struct LNode *link;
}LNode,*LinkList;
void func(LNode *h,int n){
    LNode *p = h,*r;
    int *q,m;
    /*
     * 申请n+1个位置的辅助空间
     */
    q =(int *)malloc(sizeof(int)*(n+1));
    /*
     * 数组元素初值置0
     */
    for (int i = 0; i < n+1; ++i) {
        *(q+1) = 0;
    }
    while (p ->link!=NULL)
    {
        m = p->link ->data>0>?p->link->data:p->link->data;
        /*
         * 判断该结点的data是否已出现过
         */
        if (*(q+m)==0)
        {
            /*
             * 首次出现
             */
            *(q+m)=1;
            /*
             * 保留
             */
            p = p->link;
        } else
        {
            /*
             * 重复出现
             */
            r = p->link;
            /*
             * 删除
             */
            p ->link = r->link;
            free(r);
        }
    }
    free(q);
}