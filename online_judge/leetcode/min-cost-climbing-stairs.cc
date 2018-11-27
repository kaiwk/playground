#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if (n == 1 || n == 2) return 0;

        int p0 = 0, p1 = 0, pi = 0;
        for (int i = 2; i <= n; ++i) {
            pi = min(p1+cost[i-1], p0+cost[i-2]);
            p0 = p1;
            p1 = pi;
        }
        return pi;
    }
};
