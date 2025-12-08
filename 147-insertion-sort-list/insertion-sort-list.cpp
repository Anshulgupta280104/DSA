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
    ListNode* insertionSortList(ListNode* head) {
        if (!head) return nullptr;

        ListNode* dummy = new ListNode(INT_MIN); // dummy sorted list head
        
        while (head != nullptr) {
            ListNode* nextNode = head->next; // preserve next
            
            // Find correct position in sorted list
            ListNode* curr = dummy;
            while (curr->next != nullptr && curr->next->val < head->val) {
                curr = curr->next;
            }

            // Insert node
            head->next = curr->next;
            curr->next = head;

            // Move to next original node
            head = nextNode;
        }

        return dummy->next;
    }
};
