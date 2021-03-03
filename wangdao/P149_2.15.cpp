/**
 * 设有一棵满二叉树（所有的结点值均不同），已知其先序序列为pre，设计一个算法求其后序序列post
 */
#include <iostream>
#include <vector>
using namespace std;
typedef struct BiTNode{
    int val;
    struct BiTNode *left,*right;
}BiTNode,*BiTree;
void PreToPost(int pre[],int l1, int h1, int post[],int l2,int h2){
    int half;
    if (h1>=l1){
        post[h2] = pre[l1];
        half = (h1 - l1)/2;
        PreToPost(pre,l1+1,l1+half,post,l2,l2+half-1);
        PreToPost(pre,l1+half+1,h1,post,12+half,h2-1);
    }
}
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
typedef struct TreeNode{
    int val;
    struct TreeNode *left,*right;
}TreeNode;
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int l1 = 0;
        int l2 = 0;
        int h1 = preorder.size()-1;
        int h2 = preorder.size()-1;
        PreToPost(preorder,l1,h1,inorder,l2,h2);
        while (!inorder.empty()){
            cout<<inorder.front()<<endl;
            inorder.erase(inorder.begin());
        }
        return NULL;

    }
    void PreToPost(vector<int> pre,int l1, int h1, vector<int> post,int l2,int h2){
        int half;
        if (h1>=l1){
            post[h2] = pre[l1];
            half = (h1 - l1)/2;
            PreToPost(pre,l1+1,l1+half,post,l2,l2+half-1);
            PreToPost(pre,l1+half+1,h1,post,12+half,h2-1);
        }
    }
};