#define LEETCODE_7

class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while (x) {
            int tmp = res * 10 + x % 10;
            if (tmp / 10 != tmp)
                return 0;
            res = tmp;
            x /= 10;
        }
        return res;
    }
};
