#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int count = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (i >= 1 && nums[i] == nums[i-1]) continue;
            int target = nums[i] + k;
            for (size_t j = i+1; j < nums.size(); ++j) {
                if (nums[j] == target) {
                    ++count;
                    break;
                }
                if (nums[j] > target) break;
            }
        }
        return count;
    }
};
