#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> map;
        vector<int> res;

        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            int tmp = target - nums[i];
            if (map.count(tmp) && map[tmp] != i) {
                res.push_back(i);
                res.push_back(map[tmp]);
                break;
            }
        }

        return res;
    }
};
