#include <vector>

using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i-1] > nums[i]) {
                if (i < 2 || nums[i] > nums[i-2]) nums[i-1] = nums[i];
                else nums[i] = nums[i-1];
                ++cnt;
            }
            if (cnt >= 2) return false;
        }
        return true;
    }
};
