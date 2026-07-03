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
        ListNode* dummy = new ListNode(-1);
        ListNode* current = dummy;

        int carry = 0;

        while(l1 != nullptr || l2 != nullptr || carry != 0){
            int sum = carry;

            if (l1 != nullptr){
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr){
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;

            current->next = new ListNode(sum % 10);
            current = current->next;

        }

        return dummy-> next;
    }
};

/*
Time Complexity: O(max(n, m))

Reason:
- We visit each node of both linked lists only once.
- There are no nested loops.
- The loop runs until the longer list ends (plus one extra iteration if there is a carry).

Space Complexity: O(max(n, m))

Reason:
- A new linked list is created to store the result.
- In the worst case, it contains max(n, m) + 1 nodes (if there is a final carry).
*/