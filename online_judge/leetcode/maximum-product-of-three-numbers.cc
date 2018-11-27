#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();

        if (n == 3) return nums[0]*nums[1]*nums[2];

        sort(nums.begin(), nums.end());
        vector<int> neg;
        vector<int> pos;

        for (int i = 0; i < n; ++i) {
            if (nums[i] < 0) neg.push_back(nums[i]);
            else pos.push_back(nums[i]);
        }

        int n1 = neg.size(), n2 = pos.size();

        if (neg.size() <= 1) return pos[n2-1] * pos[n2-2] * pos[n2-3]; // 0 or 1 negtives
        else if (n2 == 0) return neg[n1-1] * neg[n1-2] * neg[n1-3];    // 3 negtives, because there isn't any positive number
        else return max(neg[0]*neg[1]*pos[n2-1], pos[n2-1] * pos[n2-2] * pos[n2-3]); // otherwise, 2 negtives vs 0 negtives
    }
};
