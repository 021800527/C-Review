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