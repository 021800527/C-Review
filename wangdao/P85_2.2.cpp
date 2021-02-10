/*
 *Q是一个队列，S是一个空栈
 * 实现将队列中的元素逆置的算法
 */
void Inverser(Stack S,Queue Q){
    while (!QueueEmpty(Q)){
        x = DeQueue(Q);
        Push(S,x);
    }
    while (!StackEmpty(S)){
        Pop(S,x);
        EnQueue(Q,x);
    }
}