#include <iostream>
using namespace std;
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
/*不要迷信head*/
class Solution {
    public:
        ListNode* deleteNode(ListNode* head, int val) {
            ListNode *curr =new(ListNode);
            curr = head;
            ListNode *pre = new (ListNode);
            pre->next = head;
            ListNode *res = pre;
            while(curr!=NULL)
            {
                if(curr->val==val)
                {
                    pre->next = curr->next;
                    break;
                }
                pre = curr;
                curr = curr->next;
            }
            return res->next;
        }
};