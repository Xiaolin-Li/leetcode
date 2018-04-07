#define LEETCODE_55

class Solution {
public:
    bool canJump(vector<int> &nums) {
        int max_reach = 0;
        for (int i = 0; i <= max_reach && i < nums.size() - 1; i++) {
            max_reach = max(max_reach, i + nums[i]);
        }
        if (max_reach < nums.size() - 1)
            return false;
        return true;
    }
};
