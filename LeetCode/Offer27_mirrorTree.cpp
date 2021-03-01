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
using namespace std;
typedef struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x),left(NULL),right(NULL){}
};
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if(!root)
            return NULL;
        TreeNode *transition = new TreeNode(0);
        transition ->left = root ->left;
        root -> left = root ->right;
        root -> right = transition ->left;
        if (root->left!=NULL)
            root -> left = mirrorTree(root->left);
        else
            root ->left = NULL;
        if (root->right != NULL)
            root -> right = mirrorTree(root->right);
        else
            root ->right = NULL;
        return root;
    }
};