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
  ListNode *reverseKGroup(ListNode *head, int k)
  {

    if (k == 1)
      return head;

    ListNode *cur = head;

    // calculating size
    int size = 0;
    while (cur != NULL)
    {
      size++;
      cur = cur->next;
    }

    // possible sets of size k
    int maxset = size / k;

    cur = head;
    ListNode *headtemp = head;
    ListNode *prev;
    int c = 1;
    int sets = 0;

    while (cur != NULL && maxset != sets)
    {

      ListNode *temp = cur->next->next;
      cur->next->next = headtemp;
      headtemp = cur->next;
      cur->next = temp;

      c++;
      if (c == k)
      {
        if (sets < 1)
        {
          head = headtemp;
          prev = cur;
        }
        else
        {
          prev->next = headtemp;
          prev = cur;
        }
        c = 1;
        sets++;
        cur = cur->next;
        headtemp = cur;
      }
    }
    return head;
  }
};
