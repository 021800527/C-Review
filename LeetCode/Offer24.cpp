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
    ListNode *next;
};
class MySolution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head==NULL)
            return head;
        int num;
        ListNode *Node = head;
        num = 1;
        while (head->next!=NULL)
        {
            num ++;
            head = head->next;
        }
        head = Node;
        int a[num];
        a[0]=head->val;
        for (int i = 1; i < num; i++) {
            a[i]=head->next->val;
            head = head->next;
        }
        head = Node;
        head->val = a[num-1];
        for (int i = num-2; i >=0 ; i--) {
            head->next->val = a[i];
            head = head->next;
        }
        head = Node;
        return head;
    }
};
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL;
        ListNode *curr = head;
        while(curr){
            ListNode *next = curr ->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return curr;
    }

};
int main(){

}