#include <iostream>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
};
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head->val == 1){
            struct ListNode *s = new ListNode;
            if(s==NULL)
                return head;
            s->val = 9999;
            s->next=head->next;
            head->next = s;
        }
        return head;
    }
};

