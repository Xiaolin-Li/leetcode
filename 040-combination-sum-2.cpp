#define LEETCODE_40

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int> &nums, int target){
        vector<vector<int>> res;
        vector<int> cur;
        sort(nums.begin(), nums.end());
        dfs(nums, res, cur, target, 0);
        return res;
    }

    void dfs(vector<int> &nums, vector<vector<int>> &res, vector<int> &cur,
            int remain, int start) {
        if (remain < 0)
            return;
        if (remain == 0) {
            res.push_back(cur);
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i-1])
                continue;
            cur.push_back(nums[i]);
            dfs(nums, res, cur, remain - nums[i], i + 1);
            cur.pop_back();
        }
    }
};
