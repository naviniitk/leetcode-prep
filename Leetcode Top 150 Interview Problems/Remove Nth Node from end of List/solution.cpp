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
class Solution
{
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *fast = head, *slow = head;
    for (int i = 0; i < n; i++)
      fast = fast->next;
    if (!fast)
      return head->next;
    while (fast->next) // Basically fast is n places ahead of slow so while fast -> next is Null then slow will be nth from behind
      fast = fast->next, slow = slow->next;
    slow->next = slow->next->next;
    return head;
  }
};
