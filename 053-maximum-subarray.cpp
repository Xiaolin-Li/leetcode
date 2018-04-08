#define LEETCODE_53

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        if (nums.empty())
            return 0;
        int curMax = nums[0];
        int totalMax = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (curMax > 0)
                curMax += nums[i];
            else
                curMax = nums[i];
            if (curMax > totalMax)
                totalMax = curMax;
        }
        return totalMax;
    }
};
