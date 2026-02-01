/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        // min heap (value, node)
        priority_queue<
            pair<int, ListNode*>,
            vector<pair<int, ListNode*>>,
            greater<pair<int, ListNode*>>
        > pq;

        // push first node of every list
        for(auto node : lists) {
            if(node) pq.push({node->val, node});
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            ListNode* curr = top.second;

            tail->next = curr;
            tail = curr;

            if(curr->next)
                pq.push({curr->next->val, curr->next});
        }

        return dummy.next;
    }
};
