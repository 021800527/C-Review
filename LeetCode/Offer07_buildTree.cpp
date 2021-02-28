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
#include <vector>
using namespace std;
typedef struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x),left(NULL),right(NULL){}
};
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()||inorder.empty())
            return NULL;
        TreeNode *root = new TreeNode(preorder.front());
        preorder.erase(preorder.begin());
        vector<int>Left;
        vector<int>Right;
        while (inorder.front()!=root->val){
            Left.push_back(inorder.front());
            inorder.erase(inorder.begin());
        }
        inorder.erase(inorder.begin());
        if (!Left.empty())
            root -> left = buildTree(preorder,Left);
        else
            root -> left = NULL;
        if (!inorder.empty())
            root -> right = buildTree(preorder,inorder);
        else
            root -> right = NULL;
        return root;
    }
};