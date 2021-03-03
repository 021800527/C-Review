/**
 * 设计一个算法将二叉树的叶结点按从左到右的顺序连成一个单链表，表头指针为head。
 * 二叉树按二叉链表方式存储，链接时用叶结点的右指针域来存放单链表指针
 */
#include <iostream>
using namespace std;
typedef struct BiTNode{
    int val;
    struct BiTNode *left, *right;
}BiTNode,*BiTree;
typedef struct LinkNode{
    int data;
    struct LinkNode *next;
}LinkNode,*LinkList;
/*
 * 全局变量
 */
BiTree head = NULL;
BiTree pre = NULL;
BiTree InOrder(BiTree bt){
    if (bt){
        /*
         * 中序遍历左子树
         */
        InOrder(bt->left);
        /*
         * 叶结点
         */
        if (bt->left == NULL && bt->right == NULL)
            /*
             * 处理第一个叶结点
             */
            if (pre==NULL){
                head = bt;
                pre = bt;
            }
            /*
            * 将叶结点链入链表
            */
            else{
                pre->right = bt;
                pre = bt;
            }
            /*
             * 中序遍历右子树
             */
        InOrder(bt->right);
        /*
         * 设置链表尾
         */
        pre -> right = NULL;
    }
    return head;
}