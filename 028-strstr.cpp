#define LEETCODE_28

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty())
            return 0;
        if (haystack.empty())
            return -1;
        if (haystack.size() < needle.size())
            return -1;

        for (int i = 0; i <= haystack.size() - needle.size(); i++) {
            cout << i << endl;
            if (haystack[i] == needle[0]) {
                bool flag = true;
                for (int j = 1; j < needle.size(); j++) {
                    if (haystack[i + j] != needle[j]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    return i;
                }
            }
        }
        return -1;
    }
};
