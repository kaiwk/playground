#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int s = target - nums[i];
            for (int j = i+1; j < n; ++j) {
                if (nums[j] == s) return {i, j};
            }
        }
        return {0,0};
    }

    vector<int> twoSum2(vector<int>& nums, int target) {
        int n = nums.size();
        map<int, int> m;
        for (int i = 0; i < n; ++i) {
            int s = target - nums[i];
            m.insert(pair<int, int>(s, i));
            map<int, int>::iterator iter = m.find(nums[i]);
            if (iter != m.end() && iter->second != i) {
                return {iter->second, i};
            }
        }
        return {0,0};
    }

};
