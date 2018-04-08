#define LEETCODE_113

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(res, path, root, sum);
        return res;
    }

    void dfs(vector<vector<int>> &res, vector<int> &path, TreeNode *root, int sum) {
        if (!root)
            return;

        path.push_back(root->val);
        if (root->val == sum && !root->left && !root->right) {
            res.push_back(path);
        } else {
            if (root->left) {
                dfs(res, path, root->left, sum - root->val);
            }
            if (root->right) {
                dfs(res, path, root->right, sum - root->val);
            }
        }
        path.pop_back();
    }
};
