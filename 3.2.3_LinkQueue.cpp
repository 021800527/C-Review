/*
 * 链式队列结点
 */
typedef struct LinkNode{
    int data;
    struct LinkNode *next;
}LinkNode;
/*
 * 链式队列
 */
typedef struct {
    /*
     * 队列的队头和队尾指针
     */
    LinkNode *front,*raar;
}LinkQueue;