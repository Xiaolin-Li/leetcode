#define LEETCODE_18

class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        vector<vector<int>> res;
        if (nums.size() < 4) {
            return res;
        }

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 3; i++) {
            if (nums[i] > 0 && nums[i] > target)
                break;
            for (int j = i + 1; j < nums.size() - 2; j++) {
                int tmp = nums[i] + nums[j];
                if (tmp > 0 && tmp > target)
                    break;
                int l = j + 1;
                int r = nums.size() - 1;
                while (l < r) {
                    int sum = tmp + nums[l] + nums[r];
                    if (sum < target)
                        l++;
                    else if (sum > target)
                        r--;
                    else {
                        res.push_back(
                                vector<int>{nums[i], nums[j], nums[l], nums[r]});
                        while (l < r && nums[l] == nums[l+1])
                            l++;
                        while (l < r && nums[r] == nums[r-1])
                            r--;
                        l++;
                        r--;
                    }
                }
                while (j < nums.size() && nums[j] == nums[j+1])
                    j++;
            }
            while (i < nums.size() && nums[i] == nums[i+1])
                i++;
        }
        return res;
    }
};
