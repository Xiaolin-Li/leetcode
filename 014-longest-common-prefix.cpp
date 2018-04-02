#define LEETCODE_14

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty())
            return "";
        string prefix;
        for (int i = 0; i < strs[0].size(); i++) {
            for (int j = 0; j < strs.size(); j++) {
                if (i >= strs[j].size() || strs[j][i] != strs[0][i])
                    return prefix;
            }
            prefix += strs[0][i];
        }
        return prefix;
    }
};
