/*
 * 给定两个单链表，编写算法找出两个链表的公共结点。
 */
#include <iostream>
using namespace std;
typedef struct LNode{
    int length;
    int data;
    struct LNode *next;
}LNode,*LinkList;
LNode *Search_1st_Common(LinkList &L1,LinkList &L2){
    int dist;
    /*
     * 本算法实现在线性的时间内找到两个单链表的第一个公共结点
     */
    /*
     * 计算两个链表的表长
     */
    int len1 = L1->length;
    int len2 = L2->length;
    /*
     * 分别指向表长较长和较短的链表
     */
    LinkList longList,shortList;
    if (len1>len2){
        longList = L1->next;
        shortList = L2->next;
        dist = len1 - len2;
    }
    else
    {
        longList = L2 ->next;
        shortList = L1 ->next;
        dist = len2 - len1;
    }
    /*
     * 表长的链表先遍历到idst个结点
     */
    while (dist--)
        longList = longList -> next;
    /*
     * 同步寻找公共结点
     */
    while (longList!=NULL)
        if (longList ==shortList)
            return longList;
        else
        {
            longList = longList -> next;
            shortList = shortList -> next;
        }
        return NULL;
}