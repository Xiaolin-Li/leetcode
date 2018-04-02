#define LEETCODE_12

class Solution {
public:
    string intToRoman(int num) {
        static const struct {
            int value;
            const char *roman;
        } table[] = {
            {1000, "M"},
            {900, "CM"},
            {500, "D"},
            {400, "CD"},
            {100, "C"},
            {90, "XC"},
            {50, "L"},
            {40, "XL"},
            {10, "X"},
            {9, "IX"},
            {5, "V"},
            {4, "IV"},
            {1, "I"}
        };

        string res;
        for (int i = 0; num; i++) {
            while (num >= table[i].value) {
                num -= table[i].value;
                res += table[i].roman;
            }
        }
        return res;
    }
};
