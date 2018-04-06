#define LEETCODE_27

class Solution {
public:
    int removeElement(vector<int> &nums, int val) {
        if (nums.empty())
            return 0;
        int pos = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val)
                nums[pos++] = nums[i];
        }
        return pos;
    }
};
