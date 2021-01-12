#include <iostream>
using namespace std;
struct ListNode{
    int val;
    struct ListNode *next;
};
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = l1;
        if(l1==NULL&&l2!=NULL)
            return l2;
        if(l1!=NULL&&l2==NULL)
            return l1;
        if(l1==NULL&&l2==NULL)
            return NULL;
        if(l1->val<=l2->val){
            head = l1;
            l1 = l1->next;
        }
        else{
            head = l2;
            l2 = l2->next;
        }
        ListNode *res = head;
        while(l1!=NULL&&l2!=NULL){
            if(l1->val<=l2->val){
                head ->next = l1;
                l1 = l1->next;
                head = head -> next;
            }
            else{
                head ->next = l2;
                l2 = l2->next;
                head = head -> next;
            }
        }
        if(l1==NULL&&l2!=NULL){
            head ->next = l2;
        }
        if(l1!=NULL&&l2==NULL){
            head ->next = l1;
        }
        return res;
    }
};