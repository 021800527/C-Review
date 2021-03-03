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
#include <vector>
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
        return Choose(Search(root,p->val),Search(root,q->val));
    }
    vector<TreeNode*>Search(TreeNode* root,int x){
        stack<TreeNode*>S;
        vector<TreeNode*>V;
        TreeNode *p = root;
        TreeNode *r = NULL;
        while (p||!S.empty()){
            if (p){
                S.push(p);
                p = S.top();
                p = p -> left;
            }
            else
            {
                p = S.top();
                if (p->right && p->right!=r){
                    p = p ->right;
                    S.push(p);
                    p = p -> left;
                }
                else
                {
                    p = S.top();
                    S.pop();
                    if (p->val ==x) {
                        V.push_back(p);
                        while (!S.empty()) {
                            V.push_back(S.top());
                            S.pop();
                        }
                    }
                    r = p;
                    p = NULL;
                }
            }
        }
        return V;
    }
    TreeNode* Choose(vector<TreeNode*>V1, vector<TreeNode*>V2){
        int Size1 = V1.size();
        int Size2 = V2.size();
        int i ;
        int j ;
        int flag = 0;
        for (i = 0; i < Size1; ++i) {
            for (j = 0; j < Size2; ++j) {
                if (V1[i]->val==V2[j]->val)
                {
                    flag = 1;
                    break;
                }
            }
            if (flag==1)
                break;
        }
        return V1[i];
    }
};