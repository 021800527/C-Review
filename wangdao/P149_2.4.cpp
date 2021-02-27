/**
 * 试给出二叉树的自下而上，从右到左的层次遍历算法
 */
#include <iostream>
#include <stack>
#include <queue>
using namespace std;
typedef struct BiTNode{
    int data;
    struct BiTNode *left,*right;
}BiTNode,*BiTree;
void InvertLevel(BiTree bt){
    if (!bt)
        return;
    /*
     * 初始化栈，栈中存放二叉树结点的指针
     */
    stack<BiTNode*>s;
    /*
     * 队列初始化，队列中存放二叉树结点的指针
     */
    queue<BiTNode*>q;
    q.push(bt);
    while (!q.empty()){
        auto node = q.front();
        q.pop();
        s.push(node);
        if (node->left!=NULL)
            q.push(node->left);
        if (node->right!=NULL)
            q.push(node->right);
    }
    while (!s.empty()){
        auto node = s.top();
        s.pop();
        cout<<node->data;
    }
}