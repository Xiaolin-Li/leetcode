#define LEETCODE_80

class Solution {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        int p1 = m - 1 , p2 = n - 1, tar = m + n - 1;

        while (p2 >= 0) {
            if (p1 >= 0 && nums1[p1] > nums2[p2])
                nums1[tar--] = nums1[p1--];
            else
                nums1[tar--] = nums2[p2--];
        }
    }
};
