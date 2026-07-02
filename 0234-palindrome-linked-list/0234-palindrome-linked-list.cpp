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
    bool isPalindrome(ListNode* head) {
        vector<int> v;

        ListNode* temp = head;

        while (temp != NULL) {
            v.push_back(temp->val);
            temp = temp->next;
        }

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }

        // temp is the another pointer starts from the prevw
        temp = prev;
        int i = 0;
        while (temp != NULL) {
            if (temp->val != v[i]) {
                return false;
            }
            temp = temp->next;
            i++;
        }
        return true;
    }
};