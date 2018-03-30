#define LEETCODE_6


class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows < 2)
            return s;
        int count = s.size() / (2*numRows-2);
        if (s.size() % (2*numRows-2)) {
            count++;
        }

        string res;
        for (unsigned i = 0; i < numRows; i++) {
            for (unsigned j = 0; j < count; j++) {
                if (i == 0) {
                    res.push_back(s[2*j*(numRows-1)]);
                    continue;
                }
                unsigned pos = (2*j+1)*(numRows-1);
                if (i == numRows -1 && pos < s.size()) {
                    res.push_back(s[pos]);
                    continue;
                }
                unsigned tmp = numRows-1-i;
                unsigned pos1 = pos - tmp;
                unsigned pos2 = pos + tmp;
                if (pos1 < s.size())
                    res.push_back(s[pos1]);
                if (pos2 < s.size())
                    res.push_back(s[pos2]);
            }
        }
        return res;
    }
};
