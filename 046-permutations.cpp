#define LEETCODE_46

class Solution {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> res;
        if (!nums.empty()) {
            allPermutations(nums, res, 0, nums.size() - 1);
        }
        return res;
    }

    void allPermutations(vector<int> &nums, vector<vector<int>> &res,
                        int start, int end) {
        if (start == end) {
            res.push_back(nums);
            return;
        }

        for (int i = start; i <= end; i++) {
            swap(nums[start], nums[i]);
            allPermutations(nums, res, start + 1, end);
            swap(nums[start], nums[i]);
        }
    }
};
