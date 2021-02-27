/*
 * 已知一棵二叉树按顺序存储结构进行存储，设计一个算法，求编号分别为i和j的两个结点的最近的公共祖先结点的值
 */
int Comm_Ancestor(SqTree T, int i, int j){
    /*
     * 本算法在二叉树中查找结点i和结点j的最近公共祖先结点
     */
    /*
    * 结点存在
    */
    if (T[i] != '#' && T[j] != '#') {
        /*
         * 两个编号不同时循环
         */
        while (i != j) {
            /*
             * 向上找i的祖先
             */
            if (i > j)
                i = i / 2;
            else
                j = j / 2;
        }
    }
    return T[i];
}