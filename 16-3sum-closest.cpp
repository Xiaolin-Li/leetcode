#define LEETCODE_16

class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        if (nums.size() < 3)
            return 0;
        sort(nums.begin(), nums.end());
        int res = 0;
        int closest = INT_MAX;

        for (int i = 0; i < nums.size() - 2; i++) {
            int l = i + 1;
            int r = nums.size() - 1;

            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum < target) {
                    if (target - sum < closest) {
                        closest = target - sum;
                        res = sum;
                    }
                    l++;
                } else if (sum > target) {
                    if (sum - target < closest) {
                        closest = sum - target;
                        res = sum;
                    }
                    r--;
                } else {
                    return sum;
                }
            }
        }
        return res;
    }
};
