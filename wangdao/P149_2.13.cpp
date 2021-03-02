/**
 * 假设二叉树采用二叉链表存储结构，设计一个算法，求非空二叉树b的宽度（即具有结点数最多的你那一层的结点个数）
 */
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
#include <queue>
using namespace std;
typedef struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
}TreeNode,*BiTree;
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        cout<<Nums(root);
        return NULL;
    }
    int Nums(TreeNode *root) {
        queue<TreeNode *> Q;
        vector<int> res;
        TreeNode *p;
        int max = 0;
        int num = -1;
        if (root == NULL)
            return max;
        Q.push(root);
        while (!Q.empty()) {
            int size = Q.size();
            if (size > max)
            {
                max = size;
                num++;
            }
            for (int i = 0; i <size; ++i) {
                p = Q.front();
                Q.pop();
                if (p->left != NULL)
                    Q.push(p->left);
                if (p->right != NULL)
                    Q.push(p->right);
            }
        }
        return num;
    }
};