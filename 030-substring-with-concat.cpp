#define LEETCODE_30

class Solution {
public:
    vector<int> findSubstring(string s, vector<string> &words) {
        vector<int> res;
        if (s.empty() || words.empty())
            return res;

        unordered_map<string, int> words_map;
        for (const auto &word : words)
            words_map[word]++;

        int word_count = words.size();
        int word_len = words[0].size();

        for (int i = 0; i <= (int)s.size() - word_count*word_len; i++) {
            unordered_map<string, int> seen;
            int cur = i;
            string word = s.substr(cur, word_len);
            int cnt = 0;
            for (; cnt < word_count && words_map.count(word); cnt++) {
                seen[word]++;
                if (seen[word] > words_map[word])
                    break;
                cur += word_len;
                word = s.substr(cur, word_len);
            }
            if (cnt == word_count) {
                res.push_back(i);
            }
        }

        return res;
    }
};
