/*
 * 定义栈中元素的最个数
 */
#define MaxSize 10
typedef struct {
    /*
     * 静态数组存放栈中元素
     */
    int data[MaxSize];
    /*
     * 0号栈顶指针
     */
    int top0;
    /*
     * 1号栈顶指针
     */
    int top1;
}ShStack;
/*
 * 初始化栈
 */
void InitStack(ShStack &S){
    S.top0 = -1;
    S.top1 = MaxSize;
}
/*
 * 栈满的条件:top0 + 1 = top1
 */