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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head; // slow pointer initialized with the head
        ListNode* fast = head; // fast pointer initialized with the head

        // fast != NULL : for condition where no of nodes are odd
        // fast -> next != NULL : for condition where no of nodes are even

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;       // slow moves by 1
            fast = fast->next->next; // fast moves by 2
        }
        return slow;
    }
};