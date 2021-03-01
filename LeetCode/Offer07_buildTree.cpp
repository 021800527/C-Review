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
class TimeOut_Solution {
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
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode *root ;
        int left = 0;
        int right = preorder.size();
        root = RebuildTree(preorder,inorder,left,right);
        return root;
    }
    TreeNode* RebuildTree(vector<int>& preorder,vector<int> inorder,int left, int right){
        if (preorder.empty() || left==right)
            return NULL;
        TreeNode *head = new TreeNode(preorder.front());
        head ->val = preorder.front();
        for (int i = left; i < right; ++i) {
            if (head ->val == inorder[i]){
                preorder.erase(preorder.begin());
                head -> left = RebuildTree(preorder,inorder,left,i);
                head ->right = RebuildTree(preorder,inorder,i+1,right);
                break;
            }
        }
        return head;
    }
};