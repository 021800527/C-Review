/*
 * 若希望循环队列中的元素都能得到利用，则需设置一个标志域tag，
 * 并以tag的值为0或1来区分队头指针front和队尾指针rear相同时的队列状态是“空”还是“满”。
 * 试编写与此结构相应的入队和出队算法
 */
/*
 * 在循环队列的类型结构中，增设一个tag的整型变量，进队时置tag为1，出队时置tag为0
 * 因为只有入队操作可能导致队满，也只有出队操作可能导致队空
 * 队列Q初始时，置tag = 0 、 front = rear = 0.这样的队列四要素如下：
 * 队空条件：Q.front == Q.rear 且 Q.tag == 0
 * 队满条件：Q.front == Q.rear 且 Q.tag == 1
 * 进队操作：Q.data【Q.rear】 = x ；Q.rear = （Q.rear + 1）% MaxSize ； Q.tag = 1.
 * 出队操作：x = Q.data[Q.front] ; Q.front = (Q.front + 1) % MaxSize ; Q.tag = 0.
 */
#include <iostream>
using namespace std;
#define MaxSize 10
typedef struct SqQueue{
    int data[MaxSize];
    int front = 0,rear = 0;
    int tag;
}SqQueue;
/*
 * 入队算法
 */
int EnQueue(SqQueue &Q , int x){
    /*
     * 两个条件都满足时则队满
     */
    if (Q.front == Q.rear && Q.tag ==1)
        return 0;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear+1)% MaxSize;
    Q.tag = 1;
    return 1;
}
/*
 * 出队算法
 */
int DeQueue(SqQueue &Q , int &x){
    if (Q.front == Q.rear && Q.tag == 0)
        return 0;
    x = Q.data[Q.front];
    Q.front = (Q.front+1) % MaxSize;
    Q.tag = 0;
    return 1;
}