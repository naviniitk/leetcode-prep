// O ( N ) space approach

// Traverse the list and keep the values in a vector that are smaller than key provided. Traverse again to find the values greater than or equal to key.
// Make the list and return it.

// O ( 1 ) with TWO PASSES

// Create a node with garbage value. let say resultant -> This prevents us from checking if resultant linked list is empty or not.
// First-pass -> Traverse and add all the nodes that are smaller than key provided.
// Secong-pass -> Traverse again to add nodes that are greater than or equal to key provided.
// return resultant -> next [ next returned to remove garbage node ]

// O ( 1 ) with SINGLE PASS

// Create two nodes with garbage vales.

// small -> to have nodes with value less than key
// large -> to have nodes with value greater than or equal to key.
// Now visit each node :

// if node smaller -> add to small and small -> next = NULL
// else -> add to large and large -> next = NULL
// [ We make small/large -> next = NULL to add only a single node and break further connection, if not done , whole list after head will be added to them ]

// At end join two linked lists [ remember the garbage nodes ] ->

// make small -> next = large_head -> next : we appending large_head -> next because the first node is garbage.
// Same way while returning remove garbage node from small and return return small_head -> next.

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
    ListNode* partition(ListNode* head, int x) {
        ListNode* small = new ListNode(-1);
        ListNode* large = new ListNode(-1);
        ListNode* small_head = small;
        ListNode* large_head = large;
        
        while (head){
            if (head->val < x){
                small->next = head;
                small = small -> next;
                head = head -> next;
                small->next = NULL;
            }
            else{
                large->next = head;
                large = large -> next;
                head = head -> next;
                large -> next = NULL;
            }
        }
        small -> next = large_head -> next;

        return small_head -> next;
    }
};
