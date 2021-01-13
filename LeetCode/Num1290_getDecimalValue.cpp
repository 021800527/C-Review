/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
using namespace std;
struct ListNode{
    int val;
    struct ListNode *next;
};
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode *cur = new ListNode();
        cur = head;
        int num;
        num = 0;
        while(cur!=NULL){
            num++;
            cur = cur->next;
        }
        cur = head;
        int a[num];
        for (int i = 0; i < num; i++) {
            a[i] = cur->val;
            cur  = cur->next;
        }
        int total;
        int d;
        total=0;
        d =1;
        for (int i = num-1; i >=0 ; i--) {
            total = total+a[i]*d;
            d = d * 2;
        }
        return total;
    }
};