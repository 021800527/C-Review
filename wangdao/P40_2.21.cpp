/*
 * 21, 【2009统考真题】已知一个带有表头结点的单链表,结点结构为
    data	link
    假设该链表只给出了头指针list。在不改变链表的前提下,请设计一个尽可能高效的算法,查找链表中倒数第k个位置上的结点(k为正整数),
    若查找成功,算法输出该结点的data域的值,并返回1;否则,只返回0,要求:
    1)描述算法的基本设计思想。
    2)描述算法的详细实现步骤。
    3)根据设计思想和实现步骤,采用程序设计语言描述算法(使用C.C+或Java语言实现),关键之处请给出简要注释。
 */
/*
 * 1）利用双指针，使得第一个指针先向下走k个位置，此时两个指针之间间距为k。然后，让两个指针一起走，每次都向下移动一个位置，当先走的指针走到链表尾，后走的指针所处位置即为倒数第k个位置。

    2）
    1、定义两个指针p和q，都指向头节点。定义一个变量i=0，代表p走了几步；
    2、在p不为空并且i<k时，让p向下走k步。
    3、判断i是否等于k，如果不等于，返回0，否则执行下述步骤
    4、让p和q一起向后走，直到p到达链表尾
    5、q所处位置即为倒数第k个位置
*/
#include <iostream>
using namespace std;
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;
int Search_k(LinkList L, int k){
    LNode *p , *q;
    p=q=L;
    int i = 0;
    while(i<k && p){
        p = p->next;
        i++;
    }
    // 链表不够长，没等p走k步就结束了
    if(i!=k){
        return 0;
    }
    while(p->next){
        p = p->next;
        q = q->next;
    }
    cout<<q->data;
    return 1;

}