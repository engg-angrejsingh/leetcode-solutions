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
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

        // Push the first node of every non-empty list
        for (ListNode* head : lists) {
            if (head)
                pq.push(head);
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();

            tail->next = node;
            tail = tail->next;

            if (node->next)
                pq.push(node->next);
        }

        return dummy.next;
    }
};

/*
⏱️ Time Complexity: O(N log k)

Reason:
- N is the total number of nodes across all linked lists.
- Each node is inserted into and removed from the priority queue once.
- Each priority queue operation takes O(log k), where k is the number of linked lists.

💾 Space Complexity: O(k)

Reason:
- The priority queue stores at most one node from each linked list at any time.
- Therefore, the auxiliary space required is O(k).
*/