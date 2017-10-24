
#define LEETCODE_2

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummyRoot = new ListNode(0);
        ListNode *p = dummyRoot;
        int carry = 0;
        while (l1 || l2 || carry) {
            int t = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + (carry ? 1 : 0);
            
            if (t > 9) {
                carry = 1;
                t -= 10;
            } else {
                carry = 0;
            }

            p->next = new ListNode(t);
            p = p->next;

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        p = dummyRoot->next;
        delete dummyRoot;

        return p;
    }
};
