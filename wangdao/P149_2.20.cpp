/**
 *

请设计一个算法，将给定的表达式树（二叉树）转换为等价的中缀表达式（通过括号反映操作符的 计算次序）并输出。例如，当下列两棵表达式树作为算法的输人时：


输出的等价中缀表达式分别为(a+b)*(c*(-d))和(a*b)+(-(c-d))。 二叉树结点定义如下:
复制代码
1
2
3
4
5
typedef struct node{
    char data[10]; //存储操作数或操作符
    struct node *left, *right;
}
BTree;
要求：
 (1)给出算法的基本设计思想。
 (2)根据设计思想，采用 C 或 C++语言描述算法，关键之处给出注释。
 */

#include <iostream>
using namespace std;
typedef struct BiTNode{
    int data;
    struct BiTNode *left,*right;
}BiTNode,*BiTree;
void BtreeToExp(BiTNode *root,int deep){
    /*
     * 空节点返回
    */
    if (root == NULL) return;
    /*
     * 若为叶结点
     */
    else if (root->left == NULL && root ->right ==NULL)
        cout<<root->data;
    else{
        /*
         * 若有子表达式则加1层括号
         */
        if (deep>1) cout<<"(";
        BtreeToExp(root->left,deep+1);
        /*
         * 输出操作符
         */
        cout<<root->data;
        BtreeToExp(root->right,deep+1);
        /*
         * 若有子表达式则加1层括号
         */
        if (deep>1) cout<<")";
    }
}
void BtreeToE(BiTNode *root){
    BtreeToExp(root,1);
}