/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
struct ListNode{
    int val;
    struct ListNode *next;
};
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        int length;
        length = 0;
        ListNode *cur = new ListNode();
        cur = head;
        while (cur!=NULL){
            length++;
            cur = cur->next;
        }
        if (length==0)
            return true;
        cur = head;
        int a[length];
        int b[length];
        for (int i = 0; i < length; i++) {
            a[i] = cur->val;
            cur = cur->next;
        }
        for (int i = 0; i < length; i++) {
            b[i] =a[length-1-i];
        }
        int flag;
        flag = 1;
        for (int i = 0; i < length; i++) {
            if (a[i]!=b[i]){
                flag = 0;
                break;
            }
        }
        if (flag==1)
            return true;
        else
            return false;
    }
};