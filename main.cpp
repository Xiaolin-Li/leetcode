#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};



//#include "1-two-sum.cpp"
//#include "2-add-two.cpp"
#include "3-longest-substring.cpp"



void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(),
                                [](int ch) {return !isspace(ch);}) );
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(),
                        [](int ch) {return !isspace(ch);}).base(), input.end());
}

vector<int> stringToIntergerVector(string input) {
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
    vector<int> list = stringToIntergerVector(input);

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

