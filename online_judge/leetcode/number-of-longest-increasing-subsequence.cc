#include <vector>
#include <utility>

using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> d(n, {1, 1});
        int max_len = 0, count = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    if (d[i].first < d[j].first + 1) {
                        d[i] = {d[j].first + 1, d[j].second};
                    } else if (d[i].first == d[j].first + 1) {
                        d[i].second += d[j].second;
                    }
                }
            }
            if (max_len == d[i].first) {
                count += d[i].second;
            } else if (max_len < d[i].first){
                max_len = d[i].first;
                count = d[i].second;
            }
        }
        return count;
    }
};
