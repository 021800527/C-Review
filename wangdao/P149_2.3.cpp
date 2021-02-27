/*
 * 编写后序遍历二叉树的非递归算法
 */
/**
 * 算法思想：后序非递归遍历二叉树是先访问左子树，再访问右子树，最后访问根节点。1：沿着根的左孩子，一次入栈，直到左孩子为空。此时
 * 栈内元素依次为A B D。2:读栈顶元素：若其右孩子不空且未被访问过，将右子树转执行1；否则，栈顶元素出栈并访问。
 */
#include <iostream>
#include <stack>
using namespace std;
typedef struct BiTNode{
    int data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
void PostOrder(BiTree T){
    stack<int>S;
    BiTNode *p,*r;
    p = T;
    r = NULL;
    /*
     * 走到最左边
     */
    while (p || S.empty()){
        if (p){
            S.push(p->data);
            p = p ->lchild;
        }
        /*
         * 向右
         */
        else
        {
            /*
             * 读栈顶结点(非出栈)
             */
            p->data = S.top();
            /*
             * 若右子树存在，且未被访问过
             */
            if (p->rchild && p->rchild != r){
                /*
                 * 转向右
                 */
                p = p -> rchild;
                /*
                 * 压入栈
                 */
                S.push(p->data);
                /*
                 * 再走到左
                 */
                p = p ->lchild;
            }
            /*
             * 否则，弹出结点并访问
             */
            else{
                /*
                 * 将结点弹出
                 */
                S.pop();
                /*
                 * 访问该结点
                 */
                cout<<p->data;
                /*
                 * 记录最近访问过的结点
                 */
                r = p;
                /*
                 * 结点访问完后，重置p指针
                 */
                p = NULL;
            }
        }
    }
}