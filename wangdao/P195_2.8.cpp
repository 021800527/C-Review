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
#include <algorithm>
using namespace std;
typedef struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x),left(NULL),right(NULL){}
}TreeNode,*Tree;
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == NULL)
            return true;
        bool flag = abs(MaxHeight(root->left)-MaxHeight(root->right))<=1;
        return flag && isBalanced(root->left) && isBalanced(root->right);
    }
    int MaxHeight(TreeNode* root){
        if (root == NULL)
            return 0;
        else
            return max(MaxHeight(root->left),MaxHeight(root->right))+1;
    }
};