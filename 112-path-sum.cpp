#define LEETCODE_112

class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        return dfs(root, sum);
    }

    bool dfs(TreeNode *root, int sum) {
        if (!root)
            return false;
        if (root->val == sum && !root->left && !root->right)
            return true;
        return dfs(root->left, sum-root->val) || dfs(root->right, sum-root->val);
    }
};
