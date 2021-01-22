/*
 * 线性表(a1,a2,a3,...,an)中的元素递增有序且按顺序存储于计算机内。
 * 要求设计一算法，完成用最少时间在表中查找数值为x的元素，
 * 若找到则将其与后继元素位置交换，
 * 若找不到则将其插入表中并使表中元素仍递增有序
 */
void SearchExchangeInsert(int A[],int n,int x){
    /*
     * low和high指向顺序表下界和上界的下标
     */
    int low = 0,high = n-1,mid;
    while (low<=high){
        /*
         * 找中间位置
         */
        mid = (low+high)/2;
        /*
         * 找到x，退出while循环
         */
        if (A[mid]==x)
            break;
        else
            /*
             * 到中点mid的右半部去查
             */
            if (A[mid]<x)
                low = mid+1;
            /*
             * 到中点mid的左半部去查
             */
            else
                high = mid-1;
    }
    /*
     * 下面两个if语句只会执行一个
     */
    if (A[mid]==x&&mid!=n-1)
    {
        /*
         * 若最后一个元素与x相等，则不存在与其后继交换的操作
         */
        int t = A[mid];
        A[mid] = A[mid+1];
        A[mid+1] = t;
    }
    /*
     * 查找失败，插入数据元素x
     */
    if (low>high){
        int i;
        /*
         * 后移元素
         */
        for (i = n-1; i >high ; i--) {
            A[i+1]=A[i];
        }
        /*
         * 插入x
         */
        A[i+1] = x;
    }
}