#define LEETCODE_111

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;
        queue<TreeNode *> que;
        que.push(root);
        int depth = 0;
        while (!que.empty()) {
            depth++;
            int count = que.size();
            for (int i = 0; i < count; i++) {
                TreeNode *p = que.front();
                if (p->left)
                    que.push(p->left);
                if (p->right)
                    que.push(p->right);
                que.pop();
                if (!p->left && !p->right)
                    return depth;
            }
        }
        return -1;
    }
};
