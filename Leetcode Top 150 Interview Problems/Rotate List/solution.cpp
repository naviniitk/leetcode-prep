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
    ListNode* rotateRight(ListNode* head, int k) {
        int n = 0;
        ListNode *curr = head;
        while(curr) {
            n++;
            curr = curr->next;
        }
        if(n <= 1) return head;
        int r = k%n;
        for(int i = 1; i <= r; i++) { 
            ListNode* tail = head;
            ListNode* tailprev = NULL;
            while(tail->next) {
                tailprev = tail;
                tail = tail->next;
            }
            tail->next = head;
            tailprev->next = NULL;
            head = tail;
        }
        return head;
    }
};
