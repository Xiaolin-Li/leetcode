#define LEETCODE_17

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty())
            return res;

        const static vector<char> table[10] = {
            {},
            {},
            {'a', 'b', 'c'},
            {'d', 'e', 'f'},
            {'g', 'h', 'i'},
            {'j', 'k', 'l'},
            {'m', 'n', 'o'},
            {'p', 'q', 'r', 's'},
            {'t', 'u', 'v'},
            {'w', 'x', 'y', 'z'}
        };

        string str(digits.size(), '0');
        dfs(digits, 0, str, res, table);

        return res;
    }

    void dfs(string &digits, int index, string &str, vector<string> &res,
            const vector<char> (&table)[10]) {
        if (index >= digits.size()) {
            res.push_back(str);
            return;
        }

        for (const char &ch : table[digits[index] - '0']) {
            str[index] = ch;
            dfs(digits, index + 1, str, res, table);
        }
    }
};
