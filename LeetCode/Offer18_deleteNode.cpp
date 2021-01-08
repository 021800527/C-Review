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
class Solution {
    public:
        ListNode* deleteNode(ListNode* head, int val) {
            ListNode *curr = head;
            if (head==NULL)
                return head;
            while (head->next!=NULL){
                if(head->next->val==val){
                    if (head->next->next!=NULL)
                        head->next = head->next->next;
                    else
                        head->next = NULL;
                }
            }
            head = curr;
            return head;
        }
};