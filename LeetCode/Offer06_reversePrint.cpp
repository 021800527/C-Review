#include <iostream>
#include <vector>
using namespace std;

/**
输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。



示例 1：

输入：head = [1,3,2]
输出：[2,3,1]*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode{
    int val;
    struct ListNode *next;
};
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        int length;
        length = 0;
        ListNode *curr = head;
        while(head!=NULL){
            length++;
            head = head->next;
        }
        vector<int> res(0);
        head = curr;
        while(head!=NULL){
            res.insert(res.begin(),head->val);
            head = head->next;
        }
        return res;
    }
};