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
    ListNode *cur = head;
    ListNode *prev = new ListNode();
    prev ->next = head;
    ListNode *res = prev;
    while(cur!=NULL){
        if(cur->val == val){
            prev ->next = cur->next;
            cur = cur->next;
        }
        else{
            prev = cur;
            cur = cur->next;
        }
    }
        return res->next;
    }
};