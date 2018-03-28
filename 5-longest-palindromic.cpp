#define LEETCODE_5


class Solution {
public:
    string longestPalindrome(string s) {
        string t = "$#";
        for (int i = 0; i < s.size(); i++) {
            t += s[i];
            t += "#";
        }

        int p[t.size()] = {0};
        int id = 0, mx = 0;
        int resCenter = 0, resLen = 0;

        for (int i = 1; i < t.size(); i++) {
            if (mx <= i) {
                p[i] = 1;
            } else {
                p[i] = min(p[id * 2 - i], mx - i);
            }

            while (t[i - p[i]] == t[i + p[i]])
                p[i]++;
            if (mx < i + p[i]) {
                mx = i + p[i];
                id = i;
            }
            if (resLen < p[i]) {
                resLen = p[i];
                resCenter = i;
            }
        }

        return s.substr((resCenter - resLen) / 2, resLen - 1);

        /*
        static bool dp[1000][1000];
        memset(dp, 0, sizeof(dp));

        int size = s.size();
        int max_l = 0;
        int max_len = 1;
        for (int i = 0; i < size - 1; i++) {
            dp[i][i] = true;
            if (s[i] == s[i+1]) {
                dp[i][i+1] = true;
                max_l = i;
                max_len = 2;
            }
        }
        dp[size-1][size-1] = true;

        for (int len = 3; len <= size; len++) {
            for (int i = 0; i <= size - len; i++) {
                int j = i + len - 1;
                if (dp[i+1][j-1] && s[i] == s[j]) {
                    dp[i][j] = true;
                    max_l = i;
                    max_len = len;
                }
            }
        }

        return s.substr(max_l, max_len);
         */
    }
};
