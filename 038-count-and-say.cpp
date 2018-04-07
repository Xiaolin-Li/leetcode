#define LEETCODE_38

class Solution {
public:
    string countAndSay(int n) {
        string res = "1";

        while (--n) {
            string tmp = res;
            res = "";
            int index = 0;
            int len = 1;
            while (index < tmp.size()) {
                if (index + len < tmp.size() && tmp[index + len] == tmp[index])
                    len++;
                if (index + len == tmp.size() || tmp[index + len] != tmp[index]) {
                    res += ('0' + len);
                    res += tmp[index];
                    index += len;
                    len = 1;
                }
            }
        }
        return res;
    }
};
