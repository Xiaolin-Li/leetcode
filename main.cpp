#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <assert.h>
#include <limits.h>
#include <math.h>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


//#include "1-two-sum.cpp"
//#include "2-add-two.cpp"
//#include "3-longest-substring.cpp"
//#include "4-median-of.cpp"
//#include "5-longest-palindromic.cpp"
//#include "6-zigzag-conversion.cpp"
//#include "7-reverse-integer.cpp"
//#include "8-string-to-integer.cpp"
//#include "9-palindrome-number.cpp"
//#include "10-regular-expression.cpp"
//#include "11-container-with-most-water.cpp"
//#include "12-integer-to-roman.cpp"
//#include "13-roman-to-integer.cpp"
//#include "14-longest-common-prefix.cpp"
//#include "15-3sum.cpp"
//#include "16-3sum-closest.cpp"
//#include "17-letter-combinations.cpp"
//#include "18-4sum.cpp"
//#include "019-remove-nth-node.cpp"
//#include "020-valid-parentheses.cpp"
//#include "021-merge-two-sorted.cpp"
#include "022-generate-parentheses.cpp"




void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(),
                                [](int ch) {return !isspace(ch);}) );
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(),
                        [](int ch) {return !isspace(ch);}).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.size() - 2);

    stringstream ss;
    ss.str(input);

    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }

    return output;
}

string integerVectorToString(vector<int> list, int length=-1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for (int i : list) {
        result += to_string(i) + ", ";
    }
    return "[" + result.substr(0, result.size() - 2) + "]";
}

ListNode* stringToListNode(string input) {
    vector<int> list = stringToIntegerVector(input);

    ListNode *dummyRoot = new ListNode(0);
    ListNode *ptr = dummyRoot;
    for (int i : list) {
        ptr->next = new ListNode(i);
        ptr = ptr->next;
    }

    ptr = dummyRoot->next;
    delete dummyRoot;

    return ptr;
}

string listNodeToString(ListNode *node) {
    if (node == nullptr) {
        return "[]";
    }

    string result;
    while (node) {
        result += to_string(node->val) + ", ";
        node = node->next;
    }

    return "[" + result.substr(0, result.size() - 2) + "]";
}

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
            result.push_back(currentChar);
        }
    }
    return result;
}

int stringToInteger(string input) {
    return stoi(input);
}



#ifdef LEETCODE_1
int main() {
    Solution s;

    vector<int> nums = {3, 2, 4};
    int target = 6;

    vector<int> res = s.twoSum(nums, target);

    for (int n : res) {
        cout << n << " ";
    }

    cout << endl;
    return 0;
}
#endif

#ifdef LEETCODE_2
int main() {
    string line;
    while (getline(cin, line)) {
        ListNode *l1 = stringToListNode(line);
        
        getline(cin, line);
        ListNode *l2 = stringToListNode(line);

        ListNode *ret = Solution().addTwoNumbers(l1, l2);
        
        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}
#endif

#ifdef LEETCODE_3
int main() {
    string line;
    while (getline(cin, line)) {
        line = line.substr(1, line.size() - 2);

        cout << Solution().lengthOfLongestSubstring(line) << endl;
    }

    return 0;
}
#endif

#ifdef LEETCODE_4
int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums1 = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> nums2 = stringToIntegerVector(line);

        double ret = Solution().findMedianSortedArrays(nums1, nums2);

        cout << ret << endl;
    }

    return 0;
}
#endif


#ifdef LEETCODE_5
int main() {
    string line;
    while (getline(cin, line)) {
        line = line.substr(1, line.size() - 2);
        
        string res = Solution().longestPalindrome(line);

        cout << res << endl;
    }

    return 0;
}
#endif

#ifdef LEETCODE_6
int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        getline(cin, line);
        int numRows = stringToInteger(line);

        string ret = Solution().convert(s, numRows);
        
        cout << ret << endl;
    }

    return 0;
}
#endif

#ifdef LEETCODE_7
int main() {
    string line;
    while (getline(cin, line)) {
        int x = stringToInteger(line);

        int res = Solution().reverse(x);
        
        cout << res << endl;
    }
    return 0;
}
#endif

#ifdef LEETCODE_8
int main() {
    string line;
    while (getline(cin, line)) {
        string str = stringToString(line);

        int res = Solution().myAtoi(str);

        cout << res << endl;
    }
    return 0;
}
#endif

#ifdef LEETCODE_9
int main() {
    string line;
    while (getline(cin, line)) {
        int x = stringToInteger(line);

        bool res = Solution().isPalindrome(x);

        cout << res << endl;
    }
    return 0;
}
#endif

#ifdef LEETCODE_10
int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        getline(cin, line);
        string p = stringToString(line);

        bool res = Solution().isMatch(s, p);

        cout << res << endl;
    }
    return 0;
}
#endif

#ifdef LEETCODE_11
int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> height = stringToIntergerVector(line);

        int ret = Solution().maxArea(height);

        cout << ret << endl;
    }
    return 0;
}
#endif


#ifdef LEETCODE_12
int main() {
    string line;
    while (getline(cin, line)) {
        int num = stringToInteger(line);

        string ret = Solution().intToRoman(num);

        cout << ret << endl;
    }
    return 0;
}
#endif

#ifdef LEETCODE_13
int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);

        int ret = Solution().romanToInt(s);

        cout << ret << endl;
    }
    return 0;
}
#endif

#ifdef LEETCODE_14
int main() {
    string line;
    vector<string> strs;
    while (getline(cin, line)) {
        if (!line.empty()) {
            strs.push_back(line);
        } else {
            string ret = Solution().longestCommonPrefix(strs);
            cout << ret << endl;
            strs.clear();
        }
    }
}
#endif

#ifdef LEETCODE_15
int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);

        vector<vector<int> > ret = Solution().threeSum(nums);

        for (const auto& item : ret) {
            cout << integerVectorToString(item) << endl;
        }
    }
}
#endif

#ifdef LEETCODE_16
int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);

        getline(cin, line);
        int target = stringToInteger(line);

        int ret = Solution().threeSumClosest(nums, target);

        cout << ret << endl;
    }
    return 0;
}
#endif

#ifdef LEETCODE_17
int main() {
    string line;
    while (getline(cin, line)) {
        string digits = stringToString(line);
        vector<string> ret = Solution().letterCombinations(digits);

        for (const auto &str : ret) {
            cout << str << endl;
        }
    }
}
#endif

#ifdef LEETCODE_18
int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);

        getline(cin, line);
        int target = stringToInteger(line);

        vector<vector<int>> ret = Solution().fourSum(nums, target);
        
        for (const auto &vec : ret)
            cout << integerVectorToString(vec) << endl;
    }
}
#endif

#ifdef LEETCODE_19
int main() {
    string line;
    while (getline(cin, line)) {
        ListNode *head = stringToListNode(line);
        getline(cin, line);
        int n = stringToInteger(line);

        ListNode *ret = Solution().removeNthFromEnd(head, n);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}
#endif

#ifdef LEETCODE_20
int main() {
    string line;
    while (getline(cin, line)) {
        bool ret = Solution().isValid(line);

        cout << ret << endl;
    }
    return 0;
}
#endif

#ifdef LEETCODE_21
int main() {
    string line;
    while (getline(cin, line)) {
        ListNode *l1 = stringToListNode(line);
        getline(cin, line);
        ListNode *l2 = stringToListNode(line);

        ListNode *ret = Solution().mergeTwoLists(l1, l2);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}
#endif

#ifdef LEETCODE_22
int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);

        const vector<string> &ret = Solution().generateParenthesis(n);

        for (const auto &str : ret)
            cout << str << endl;
    }
    return 0;
}
#endif












