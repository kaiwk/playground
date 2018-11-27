#include <vector>

using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();

        if (n == 0) return 0;

        vector<int> d(n, 1);
        int max_len = 1;
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i-1]) {
                d[i] = d[i-1] + 1;
            }
            max_len = max(max_len, d[i]);
        }
        return max_len;
    }
};
