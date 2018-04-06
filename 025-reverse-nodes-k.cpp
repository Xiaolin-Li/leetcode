#define LEETCODE_25

class Solution {
public:
    ListNode* reverseKGroup(ListNode *head, int k) {
        ListNode *node = head;
        for (int i = 0; i < k; i++) {
            if (node == NULL)
                return head;
            node = node->next;
        }

        ListNode *newHead = reverse(head, node);
        head->next = reverseKGroup(node, k);
        return newHead;
    }

    ListNode* reverse(ListNode *first, ListNode *last) {
        ListNode *prev = last;
        while (first != last) {
            ListNode *tmp = first->next;
            first->next = prev;
            prev = first;
            first = tmp;
        }
        return prev;
    }
};
