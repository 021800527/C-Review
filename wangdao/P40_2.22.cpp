/*
 * 假定采用带头结点的单链表保存单词，当两个单词有相同的后缀时，则可共
享相同的后缀存储空间。例如，“loading”和“being”的存储映像如下图所示。
设strl和str2分别指向两个单词所在单链表的头结点，链表结点结构为
，请设计一个时间上尽可能高效的算法，找出由str1和str2所指的两个链表共同后缀的起始位
置(如图中字符i所在结点的位置p)。要求：
(1)给出算法的基本设计思想。
(2)根据设计思想，采用C或c++或Java
(3)说明你所设计算法的时间复杂度。

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