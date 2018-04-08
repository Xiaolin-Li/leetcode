#define LEETCODE_47

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        vector<vector<int>> res;
        if (!nums.empty()) {
            sort(nums.begin(), nums.end());
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

        unordered_set<int> umap;
        for (int i = start; i <= end; i++) {
            if (umap.find(nums[i]) == umap.end()) {
                umap.insert(nums[i]);
                swap(nums[start], nums[i]);
                allPermutations(nums, res, start + 1, end);
                swap(nums[start], nums[i]);
            }
        }
    }
};
