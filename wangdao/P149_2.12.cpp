/**
 * 在二叉树中查找值为x的结点，试编写算法（用C语言）打印值为x的结点的所有祖先，假设值为x的结点不多于一个
 */
#include <iostream>
#include <stack>
using namespace std;
typedef struct BiTNode{
    int val;
    struct BiTNode *left,*right;
    /*
     * tag=0表示左子女被访问，tag =1 表示右子女被访问
     */
    int tag ;
}BiTNode,*BiTree;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <iostream>
#include <stack>
using namespace std;
typedef struct TreeNode{
    int val;
    struct TreeNode *left,*right;
    /*
     * tag=0表示左子女被访问，tag =1 表示右子女被访问
     */
    int tag ;
}TreeNode,*BiTree;
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

    }
    void Search(TreeNode *root,int x){
        stack<TreeNode*>s;
        TreeNode *a = new TreeNode();
        a = root;
        TreeNode *r = new TreeNode();
        r = NULL;
        while (a||!s.empty()){
            if (a){
                s.push(a);
                a = s.top();
                a = a ->left;
            }
            else
            {
                a = s.top();
                if (a->right && a ->right  != r){
                    a = a->right;
                    s.push(a);
                    a = a -> left;
                }
                else{
                    a = s.top();
                    s.pop();
                    if (a ->val == x){
                        while (s.empty()){
                            cout<<s.top()<<endl;
                            s.pop();
                        }
                    }
                    r = a ;
                    a = NULL;
                }
            }
        }
    }
};