#define LEETCODE_15

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> res;
        if (nums.empty())
            return res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            if (nums[i] > 0)
                break;
            int target = 0 - nums[i];

            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                int t = nums[l] + nums[r];
                if (t > target)
                    r--;
                else if (t < target)
                    l++;
                else {
                    vector<int> triplet = {nums[i], nums[l], nums[r]};
                    res.push_back(triplet);
                    while (nums[l] == nums[l+1])
                        l++;
                    while (nums[r] == nums[r-1])
                        r--;
                    l++;
                    r--;
                }
            }

            while (nums[i] == nums[i+1])
                i++;
        }
        return res;
    }
};
