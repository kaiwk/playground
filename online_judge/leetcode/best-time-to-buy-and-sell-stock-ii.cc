#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int total = 0;
        for (int i = 1; i < n; ++i) {
            if (prices[i] > prices[i-1])
                total += prices[i] - prices[i-1];
        }
        return total;
    }
};
