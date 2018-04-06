#define LEETCODE_22

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        addPar(res, "", n, 0);
        return res;
    }

    void addPar(vector<string> &res, string s, int left, int right) {
        if (left == 0 && right == 0) {
            res.push_back(s);
            return;
        }

        if (left)
            addPar(res, s + '(', left - 1, right + 1);
        if (right)
            addPar(res, s + ')', left, right - 1);
    }
};
