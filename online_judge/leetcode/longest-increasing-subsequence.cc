#include <iostream>
#include <vector>

using namespace std;

// [1,3,6,7,9,4,10,5,6]
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int res = 1;
        vector<int> d(n, 1);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    d[i] = max(d[i], d[j] + 1);
                }
            }
            res = max(res, d[i]);
        }
        return res;
    }
};

int main() {

    Solution s;
    vector<int> in = {1, 3, 6, 7, 9, 4, 10, 5, 6};
    s.lengthOfLIS(in);
}
