/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <iostream>
#include <queue>
using namespace std;
typedef struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
}TreeNode;
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (!root)
            return ret;
        queue<TreeNode*> transition;
        transition.push(root);
        while (!transition.empty()){
            int Size = transition.size();
            ret.push_back(vector<int>());
            for (int i = 0; i < Size; ++i) {
                auto node = transition.front();
                ret.back().push_back(node->val);
                transition.pop();
                if (node->left!=NULL)
                    transition.push(node->left);
                if (node->right!=NULL)
                    transition.push(node->right);
            }
        }
        return ret;
    }
};