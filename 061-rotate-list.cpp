#define LEETCODE_61

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == NULL)
            return head;

        ListNode *tail = head;
        int len = 1;
        while (tail->next) {
            tail = tail->next;
            len++;
        }
        tail->next = head;

        if (k = k % len) {
            for (int i = 0; i < len - k; i++) {
                tail = tail->next;
            }
        }

        ListNode *newHead = tail->next;
        tail->next = NULL;
        return newHead;
    }
};
