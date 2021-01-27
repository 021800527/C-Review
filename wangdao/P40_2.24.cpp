/*
 * 设计一个算法完成以下功能
 * 判断一个链表是否有环，如果有，找出环的入口并返回，否则返回NUll
 */
#include <iostream>
using namespace std;
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,LinkList;
LNode* FindLoopStart(LNode *head){
    /*
     * 设置快慢指针两个指针
     */
    LNode *fast = head,*slow = head;
    while (slow !=NULL && fast ->next != NULL)
    {
        /*
         * 每次走一步
         */
        slow = slow ->next;
        /*
         * 每次走两步
         */
        fast = fast ->next ->next;
        /*
         * 相遇
         */
        if (slow == fast) break;
    }
    if (slow ==NULL || fast ->next ==NULL)
        /*
         * 没有环，返回NUll
         */
        return NULL;
        /*
         * 分别指向开始点、相遇点
         */
    LNode *p1 = head, *p2 =slow;
    while (p1 != p2){
        p1 = p1->next;
        p2 = p2->next;
    }
    /*
     * 返回入口点
     */
    return p1;
}