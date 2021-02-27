#include <iostream>
#include <algorithm>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x) ,left(NULL) , right(NULL){}
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;
        bool flag = abs(depth(root->left) - depth(root ->right)) <= 1;
        return flag && isBalanced(root->left) && isBalanced(root->right);
    }
    int depth(TreeNode* root){
        if (root == NULL) return 0;
        return max(depth(root->left),depth(root->right))+1;
    }
};
