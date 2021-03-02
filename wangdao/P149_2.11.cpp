/**
 * 已知二叉树以二叉链表存储，编写算法完成：对于树中每个元素值为x的结点，删去以它为根的树，并释放相应的空间
 */
#include <iostream>
#include <queue>
using namespace std;
typedef struct BiTNode{
    int val;
    struct BiTNode *left,*right;
}BiTNode,*BiTree;
/*
 * 删除以bt为根的子树
 */
void DeleteXTree(BiTree bt) {
    if (bt) {
        /*
         * 删除bt的左子树右子树
         */
        DeleteXTree(bt->left);
        DeleteXTree(bt->right);
        /*
         * 释放被删除结点所占的存储空间
         */
        free(bt);
    }
}
    /*
     * 在二叉树上查找所有以x为元素值的结点，并删除以其为根的子树
     */
    void Search(BiTree bt , int x)
    {
        /*
         * Q是存放二叉树结点指针的队列，容量足够大
         */
        if (bt){
            /*
             * 若根结点值为x，则删除整棵树
             */
            if (bt->val == x){
                DeleteXTree(bt);
                exit(0) ;
            }
            queue<BiTNode*>Q;
            Q.push(bt);
            while (!Q.empty()){
                BiTNode *p = new BiTNode ();
                Q.pop();
                /*
                 * 若左子女非空
                 */
                if (p->left)
                    /*
                     * 左子树符合规则删除左子树
                     */
                    if (p->left->val == x){
                        DeleteXTree(p->left);
                        /*
                        * 父结点的左子女置空
                        */
                        p -> left = NULL;
                    }
                /*
                 * 左子树入队列
                 */
                else{
                    Q.push(p->left);
                    p = p->left;
                }
                /*
                 * 若右子女非空
                 */
                if (p->right)
                    /*
                     * 右子女符合规则删除右子树
                     */
                    if (p->right ->val = x){
                        DeleteXTree(p->right);
                        p ->right = NULL;
                    }
                else
                    {
                    Q.push(p->right);
                    p = p -> right;
                    }
        }
    }
}