#include <iostream>
using namespace std;
struct ListNode{
    int val;
    struct ListNode *next;
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *res = new ListNode();
        res->next = head;
        ListNode *old = res;
        while(res->next!=NULL){
            if (res->next->val == val){
                res->next = res->next->next;
            }
            if (res->next!=NULL)
                res =res->next;
        }
        return res->next;
    }
};