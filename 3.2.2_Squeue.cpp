/*
 * 定义队列中元素的最大个数
 */
#define MaxSize 10
typedef struct {
    /*
     * 用静态数组存放队列元素
     */
    int data[MaxSize];
    /*
     * 队头指针和队尾指针
     */
    int front,rear;
}SqQueue;
/*
 * 初始化队列
 */
void  InitQueue(SqQueue &Q){
    /*
     * 初始时，队头、队尾指针指向0
     */
    Q.rear = Q.front = 0;
}
/*
 * 判断队伍是否为空
 */
bool QueueEmpty(SqQueue Q){
    /*
     * 队空条件
     */
    if (Q.rear == Q.front)
        return true;
    else
        return false;
}
/*
 * 入队
 */
bool EnQueue(SqQueue &Q,int x){
    /*
     * 队满则报错
     */
    if ((Q.rear + 1)%MaxSize == Q.front)
        return false;
    /*
     * 新元素插入队尾
     */
    Q.data[Q.rear] = x;
    /*
     * 队尾指针加1取模
     */
    Q.rear = (Q.rear+1)%MaxSize;
    return true;
}
/*
 * 出队（删除一个队头元素，并用x返回）
 */
bool DeQueue(SqQueue &Q,int &x){
    /*
     * 判断对队空,队空则报错
     */
    if (Q.rear == Q.front)
        return false;
    x = Q.data[Q.front];
    Q.front = (Q.front+1)%MaxSize;
    return true;
}
/*
 * 获得队头元素的值，用x返回
 */
bool GetHead(SqQueue Q,int &x){
    /*
     * 队空则报错
     */
    if (Q.rear == Q.front)
        return false;
    x = Q.data[Q.front];
    return true;
}