#define LEETCODE_29

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0 || dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        if (dividend == 0)
            return 0;

        bool sign = (dividend > 0) ^ (divisor > 0);
        unsigned x = (dividend < 0) ? negative(dividend) : dividend;
        unsigned y = (divisor < 0) ? negative(divisor) : divisor;

        int ret = posDiv(x, y);
        return sign ? negative(ret) : ret;
    }

    int posDiv(unsigned x, unsigned y) {
        int res = 0;
        for (int i = 31; i >=0; i--) {
            if ((x>>i) >= y) {
                res += (1<<i);
                x -= (y<<i);
            }
        }
        return res;
    }

    int negative(int a) {
        return add(~a, 1);
    }

    int add(int a, int b) {
        int ans = 0;
        while (b) {
            ans = a ^ b;
            b = (a & b) << 1;
            a = ans;
        }
        return ans;
    }
};
