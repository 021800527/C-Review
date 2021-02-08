/*
 * 设单链表的表头指针为L。结点结构由data和next两个域构成。其中data和next两个域构成，其中data域为字符型
 * 试设计算法判断该链表的全部n个字符是否中心对称。例如xyx、xyyx都是中心对称
 */
#include <iostream>
using namespace std;
typedef struct LNode{
    char data;
    struct LNode *next;
}LNode,*LinkList;
int dc(LinkList L, int n){
    int i ;
    /*
     * s字符栈
     */
    char s[n/2];
    /*
     * p是链表的工作指针，指向待处理的当前元素
     */
    LNode *p;
    p = L ->next ;
    /*
     * 链表前一半元素进栈
     */
    for (i = 0; i < n/2; ++i) {
        s[i] = p ->data;
        p = p ->next;
}
    /*
     * 恢复最后的i值
     */
    i--;
    /*
     * 若n是奇数，后移过中心结点
     */
    if (n%2 == 1)
        p = p ->next;
    /*
     * 检测是否中心对称
     */
    while (p!=NULL && s[i] == p ->data){
        /*
         * i充当栈顶指针
         */
        i --;
        p = p->next;
    }
    /*
     * 栈为空栈
     */
    if (i==-1)
        /*
         * 链表中心对称
         */
        return 1;
    else
        /*
         * 链表不中心对称
         */
        return 0;
}