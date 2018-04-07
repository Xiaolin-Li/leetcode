#define LEETCODE_34

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        int first = find_first(nums, target);
        int last = find_last(nums, target);
        return vector<int> {first, last};
    }

    int find_first(vector<int> &nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] > target)
                r = mid - 1;
            else if (nums[mid] < target)
                l = mid + 1;
            else {
                if (mid - 1 >= l && nums[mid - 1] == target)
                    r = mid - 1;
                else
                    return mid;
            }
        }
        return -1;
    }

    int find_last(vector<int> &nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = (l + r) /2;
            if (nums[mid] > target)
                r = mid - 1;
            else if (nums[mid] < target)
                l = mid + 1;
            else {
                if (mid + 1 <= r && nums[mid + 1] == target)
                    l = mid + 1;
                else
                    return mid;
            }
        }
        return -1;
    }
};
