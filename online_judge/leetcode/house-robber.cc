#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 0) return 0;

        int d[2];
        d[0] = 1;
        d[0] = nums[0];
        d[1] = max(nums[0], nums[1]);
        if (n <= 2)
            return d[n-1];

        int dm = 0;
        for (int i = 2; i < n; ++i) {
            dm = max(d[1], d[0]+nums[i]);
            d[0] = d[1];
            d[1] = dm;
        }
        return dm;
    }
};

int main () {
    return 0;
}
