#include <bits/stdc++.h>

// -INT_MIN =  INT_MAX + 1 = INT_MIN is undefined behavior
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (n < 0) x = 1/x;

        double res = 1.0;

        while (n != 0) {
            if (abs(n % 2) == 1) {
                res *= x;
            }
            x *= x;
            n /= 2;
        }
        return res;
    }
};
