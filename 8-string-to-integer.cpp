#define LEETCODE_8

class Solution {
public:
    int myAtoi(string str) {
        int i = 0;
        while (str[i] == ' ')
            i++;

        bool negative = false;
        if (str[i] == '-') {
            negative = true;
            i++;
        } else if (str[i] == '+') {
            i++;
        }

        int res = 0;
        for (; i < str.size(); i++) {
            if (str[i] >= '0' && str[i] <= '9') {
                if (res > INT_MAX / 10 || (res == INT_MAX / 10 && str[i] > '7')) {
                    return negative ? INT_MIN : INT_MAX;
                }
                res = res*10 + (str[i] - '0');
            } else {
                break;
            }
        }
        return negative ? -res : res;
    }
};
