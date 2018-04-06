#define LEETCODE_19

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode *node, int n) {
        if (node == NULL || n < 1)
            return NULL;
        ListNode *p1 = node;

        for (int i = 0; i < n; i++) {
            if (p1 == NULL)
                return NULL;
            p1 = p1->next;
        }

        if (p1 == NULL) {
            ListNode *ans = node->next;
            delete node;
            return ans;
        }

        ListNode *p2 = node;
        while (p1->next != NULL) {
            p1 = p1->next;
            p2 = p2->next;
        }

        ListNode *del = p2->next;
        p2->next = p2->next->next;
        delete del;
        return node;
    }
};
