/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int rem = 0;
        ListNode* ans = new ListNode();
        ListNode* head = ans;
        while(l1 && l2) {
            int val = l1->val + l2->val + rem;
            rem = val/10;
            ListNode* curr = new ListNode(val % 10);
            ans->next = curr;
            l1 = l1->next;
            l2 = l2->next;
            ans = ans->next;
        }
        while(l1) {
            int val = l1->val + rem;
            rem = val/10;
            ListNode* curr = new ListNode(val % 10);
            ans->next = curr;
            l1 = l1->next;
            ans = ans->next;
        }
        while(l2) {
            int val = l2->val + rem;
            rem = val/10;
            ListNode* curr = new ListNode(val % 10);
            ans->next = curr;
            l2 = l2->next;
            ans = ans->next;
        }
        if(rem) {
            ListNode* curr = new ListNode(rem);
            ans->next = curr;
        }
        return head->next;
    }
};
