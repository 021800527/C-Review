#include <iostream>
using namespace std;
/**输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。

示例1：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
*/
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *res  = new(ListNode);
        ListNode *old = res;
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        while(l1!=NULL && l2!=NULL)
        {
            if(l1->val<=l2->val){
                res->next = l1;
                l1 = l1->next;
                res = res->next;
            }
            else{
                res->next = l2;
                l2 = l2->next;
                res = res->next;
            }
            if(l1==NULL){
                res->next = l2;
                cout<<res->val;
                break;
            }
            if(l2==NULL){
                res->next = l1;
                break;
            }
        }
        return old->next;
    }
};
int main(){
    ListNode* l1;
    ListNode* l2;
    Solution solution;
    solution.mergeTwoLists(l1,l2);

}