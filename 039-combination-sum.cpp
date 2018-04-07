#define LEETCODE_39

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, res, cur, target, 0);
        return res;
    }

    void dfs(vector<int> &nums, vector<vector<int>> &res, vector<int> &cur,
            int remain, int start) {
        if (remain == 0) {
            res.push_back(cur);
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            if (nums[i] <= remain) {
                cur.push_back(nums[i]);
                dfs(nums, res, cur, remain - nums[i], i);
                cur.pop_back();
            }
        }
    }

};
