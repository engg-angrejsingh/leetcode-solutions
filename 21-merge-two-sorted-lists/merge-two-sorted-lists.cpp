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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy;
        ListNode* current = &dummy;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                current->next = list1;
                list1 = list1->next;
            } else {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }

        // Attach the remaining nodes
        current->next = (list1 != nullptr) ? list1 : list2;

        return dummy.next;
    }
};

/*
⏱️ Time Complexity: O(n + m)

Reason:
- Each node from both linked lists is visited exactly once.
- Here, n and m are the lengths of the two linked lists.

💾 Space Complexity: O(1)

Reason:
- Only a few pointer variables are used.
- The nodes are rearranged in place without creating a new linked list.
*/