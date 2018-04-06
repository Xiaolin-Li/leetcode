#define LEETCODE_23

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<ListNode *, vector<ListNode *>, cmpListNode> minHeap;

        for (const auto &list : lists) {
            if (list)
                minHeap.push(list);
        }

        if (minHeap.empty())
            return NULL;

        ListNode *head = minHeap.top();
        minHeap.pop();
        if (head->next)
            minHeap.push(head->next);

        ListNode *pos = head;
        while (!minHeap.empty()) {
            pos->next = minHeap.top();
            minHeap.pop();
            pos = pos->next;
            if (pos->next)
                minHeap.push(pos->next);
        }

        return head;
    }

    struct cmpListNode {
        bool operator() (const ListNode *a, const ListNode *b) {
            return a->val > b->val;
        }
    };
};
