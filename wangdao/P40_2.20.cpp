/*
 * 设头指针为L的带有表头结点的非循环双向链表，其每个节点中除有pred（前驱指针）、data（数据）、next（后继指针）域外
 * 还有一个访问频度域。在链表被启用前，其值均初始化为0。每当在链表中进行一次Locate（L,x）运算时，令元素值为x的结点中
 * freq域的值增1，并使此链表中结点保持按访问拼读非增（递减）的顺序排列，同时最近访问的结点排在频度相同的结点前面，
 * 以便使频繁访问的结点总是靠近表头。试编写符合上述要求的Locate（L,x）运算的算法，该运算为函数过程，返回找到结点的地址，类型为指针形。
 */
/*
 * 算法思想：首先在双向链表中查找数据值为x的结点，查到后，将结点从链表上摘下，然后再顺着结点的前驱链查找该结点的插入位置
 * （频度递减，且排在同频度的第一个，即向前找到第一个比它频度大的结点，插入位置为该结点之后），并插入到该位置。
 */
#include <iostream>
using namespace std;
typedef struct DLNode{
    int freq;
    int data;
    struct DLNode *pred,*next;
}DLNode,*DLinkList;
DLNode *Locate(DLinkList &L , int x){
    /*
     * p为工作指针，q为p的前驱，用于查找插入位置
     */
    DLNode *p = L->next, *q;
    while (p&&p->data != x)
        /*
         * 查找值为x的结点
         */
        p = p ->next;
    if (!p){
        cout<<"不存在值为x的结点\n"<<endl;
        return 0;
    }
    else
    {
        /*
         * 令元素值为x的结点freq域加1
         */
        p ->freq ++;
        /*
         * 将p结点从链表上摘下
         */
        if (p->next != NULL) p->next ->pred =p ->pred;
        p->pred ->next = p ->next;
        /*
         * 以下查找p结点的插入位置
         */
        q = p->pred;
        while (q!=L&&q ->freq<=p->freq)
            q = q->pred;
        p ->next = q ->next;
        /*
         * 将p结点插入，一定是排在同频率的第一个
         */
        q ->next ->pred = p;
        p ->pred = q;
        q ->next =p;
    }
    /*
     * 返回值为x的结点的指针
     */
    return p;
}