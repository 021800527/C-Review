/*
 * 按下图所示铁道进行车厢调度（注意，两侧铁道均为单向行驶道，火车调度站有一个用于调度的“栈道”）
 * 火车调度站的入口处有n节硬座和软座车厢（分别用H和S表示）等待调度，试编写算法
 * 输出对这n节车厢进行调度的操作（即入栈和出栈操作）序列
 * 以使所有的软座车厢都被调整到硬座车厢之前
 */
void Train_Arrange(char *train){
    /*
     * 用字符串train表示火车，H表示硬座,S表示软座
     */
    char *p = train , *q = train, c;
    stack s;
    /*
     * 初始化栈结构
     */
    InitStack(s);
    while (*p){
        if (*p == 'H')
            /*
             * 把H存入栈中
             */
            Push(s,*p);
        else
            /*
             * 把S调到前部
             */
            *(q++) = *p;
        p++;
    }
    while (!StackEmpty(s)){
        /*
         * 把H接在后部
         */
        Pop(s,c);
        *(q++) = c;
    }

}