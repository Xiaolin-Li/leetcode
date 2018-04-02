#define LEETCODE_4


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size(), size2 = nums2.size();
        int size = size1 + size2;
        if (size == 0)
            return 0;

        int k = (size-1) / 2 + 1;
        double val1 = findKth(nums1, nums2, 0, size1, 0, size2, k);

        if (size & 1) {
            return val1;
        }
        double val2 = findKth(nums1, nums2, 0, size1, 0, size2, k+1);
        return (val1 + val2) / 2;
        /*
        int k = (size - 1) / 2;
        int pos = findKth(nums1, nums2, k);
        double val1 = pos < size1 ? nums1[pos] : nums2[pos - size1];

        if (size & 1) {
            return val1;
        }

        int pos2 = findKth(nums1, nums2, k + 1);
        double val2 = pos2 < size1 ? nums1[pos2] : nums2[pos2 - size1];
        return (val1 + val2) / 2;
        */
    }

    int findKth(vector<int>& nums1, vector<int>& nums2, int k) {
        int size1 = nums1.size(), size2 = nums2.size();
        int l1 = 0, r1 = size1 - 1;
        int l2 = size1, r2 =  size1 + size2 - 1;
        
        int res = 0;

        while (l1 <= r1 || l2 <= r2) {
            int kPos = l1 + k;
            
            if(kPos <= r1) {
                if (l2 > r2 || nums1[kPos] <= nums2[l2 - size1]) {
                    res = kPos;
                    break;
                } else {
                    r1 = kPos - 1;
                    int mid2 = (l2 + r2) / 2;
                    if (nums2[mid2 - size1] > nums1[kPos]) {
                        r2 = mid2 - 1;
                    }
                }
            } else {
                kPos = l2 + kPos - r1 - 1;
                if (l1 > r1 || nums2[kPos - size1] >= nums1[r1]) {
                    res = kPos;
                    break;
                } else {
                    k -= (kPos - l2 + 1);
                    l2 = kPos + 1;
                    int mid1 = (l1 + r1) / 2;
                    if (nums1[mid1] < nums2[kPos - size1]) {
                        k -= (mid1 - l1 + 1);
                        l1 = mid1 + 1;
                    }
                }
            }
        }

        return res;
    }

    int findKth(vector<int>& nums1, vector<int>& nums2,
                int l1, int len1, int l2, int len2, int k) {
        if (k <= len1) {
            int t = nums1[l1 + k - 1];
            if (len2 < 1 || t <= nums2[l2]) {
                return t;
            } else {
                int mid2 = l2 + (len2 - 1) / 2;
                if (nums2[mid2] > t) {
                    len2 = mid2 - l2;
                }
                return findKth(nums1, nums2, l1, k - 1, l2, len2, k);
            }
        } else {
            int t = nums2[l2 + k - len1 - 1];
            if (len1 < 1 || t >= nums1[l1+len1-1]) {
                return t;
            } else {
                int lose = k - len1;
                return findKth(nums1, nums2, l1, len1, l2 + lose, len2 - lose, k - lose);
            }
        }
    }
};
