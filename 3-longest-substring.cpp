#define LEETCODE_3


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int c_set[128] = {0};

        int l = 0, r = 1;
        int max_len = 1;

        if (s.size() <= 1)
            return s.size();
       
        c_set[s[0]] = 1;
        while (r < s.size()) {
            if (c_set[s[r]]) {
                c_set[s[l++]] = 0;
            } else {
                c_set[s[r++]] = 1;
                if (r - l > max_len) {
                    max_len++;
                }
            }
        }

        return max_len;
    }
};
