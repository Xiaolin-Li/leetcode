#define LEETCODE_80

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        int pos = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (pos < 2 || nums[i] > nums[pos-2])
                nums[pos++] = nums[i];
        }
        return pos;
    }
};
