#define LEETCODE_24

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *p1 = head;
        ListNode *p2 = head->next;
        head = p2;
        while (p2) {
            p1->next = p2->next;
            p2->next = p1;
            if (p1->next && p1->next->next) {
                ListNode *tmp = p1->next;
                p2 = p1->next->next;
                p1->next = p2;
                p1 = tmp;
            } else
                break;
        }

        return head;
    }
};
