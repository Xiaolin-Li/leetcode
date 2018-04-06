#define LEETCODE_20

class Solution {
public:
    bool isValid(string s) {
        if (s.empty() || s.size() & 1)
            return false;
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            switch (s[i]) {
            case '(':
            case '[':
            case '{':
                st.push(s[i]);
                break;
            case ')':
                if (st.empty())
                    return false;
                if (st.top() == '(')
                    st.pop();
                break;
            case ']':
                if (st.empty())
                    return false;
                if (st.top() == '[')
                    st.pop();
                break;
            case '}':
                if (st.empty())
                    return false;
                if (st.top() == '{')
                    st.pop();
                break;
            default:
                return false;
            }
        }
        return st.empty();
    }
};
