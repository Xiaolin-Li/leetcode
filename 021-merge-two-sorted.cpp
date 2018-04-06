#define LEETCODE_21

class Solution {
public:
    ListNode* mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (!l1)
            return l2;
        if (!l2)
            return l1;

        ListNode *head = NULL;
        ListNode *pos = NULL;
        if (l1->val > l2->val) {
            pos = l2;
            l2 = l2->next;
        } else {
            pos = l1;
            l1 = l1->next;
        }

        head = pos;

        while (l1 && l2) {
            if (l1->val > l2->val) {
                pos->next = l2;
                l2 = l2->next;
            } else {
                pos->next = l1;
                l1 = l1->next;
            }
            pos = pos->next;
        }

        while (l1) {
            pos->next = l1;
            l1 = l1->next;
            pos = pos->next;
        }

        while (l2) {
            pos->next = l2;
            l2 = l2->next;
            pos = pos->next;
        }

        return head;
    }
};
