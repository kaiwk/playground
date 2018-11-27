#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int p[2] = {1, 2};
        if (n < 3) return p[n-1];

        int pi = 0;
        for (int i = 2; i < n; ++i) {
            pi = p[0] + p[1];
            p[0] = p[1];
            p[1] = pi;
        }
        return pi;
    }
};
