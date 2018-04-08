#define LEETCODE_78

class Solution {
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> res;
        vector<int> cur;
        dfs(nums, res, cur, 0, nums.size() - 1);
        return res;
    }

    void dfs(vector<int> &nums, vector<vector<int>> &res, vector<int> &cur,
            int start, int end) {
        res.push_back(cur);

        for (int i = start; i <= end; i++) {
            cur.push_back(nums[i]);
            dfs(nums, res, cur, i + 1, end);
            cur.pop_back();
        }
    }
};
