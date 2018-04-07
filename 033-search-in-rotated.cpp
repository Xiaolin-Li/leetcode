#define LEETCODE_33

class Solution {
public:
    int search(vector<int> &nums, int target) {
        int pos = -1;
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            int mid = (r + l) / 2;
            if (nums[mid] == target) {
                pos = mid;
                break;
            }

            if (nums[mid] > nums[r]) {
                if (target >= nums[l] && target < nums[mid])
                    r = mid -1;
                else
                    l = mid + 1;
            } else if (nums[mid] < nums[l]){
                if (target > nums[mid] && target <= nums[r])
                    l = mid + 1;
                else
                    r = mid - 1;
            } else {
                if (nums[mid] > target)
                    r = mid - 1;
                else
                    l = mid + 1;
            }
        }
        return pos;
    }
};
