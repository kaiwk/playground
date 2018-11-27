#include <cstdio>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if (n == 0) return 0;
        int d[n][n];

        d[0][0] = triangle[0][0];
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                int mval = INT_MAX;
                if (j - 1 >= 0) mval = min(mval, d[i-1][j-1]);
                mval = min(mval, d[i-1][j]);
                d[i][j] = mval + triangle[i][j];
                printf("d[%d][%d] = %d\n", i, j, d[i][j]);
            }
        }
        return *min_element(d[n-1], d[n-1] + n);
    }

    int minimumTotalOpt(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if (n == 0) return 0;
        int d[n];
        int d1[n];

        d[0] = d1[0] = triangle[0][0];
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                d1[j] = d[j];
                int mval = INT_MAX;
                if (j - 1 >= 0) mval = min(mval, d1[j-1]);
                if (j <= i-1) mval = min(mval, d1[j]);
                d[j] = mval + triangle[i][j];
            }
        }
        return *min_element(d, d + n);
    }
};

int main () {

    vector<vector<int>> in = {   {-1},
                                {3,2},
                              {-3,1,-1}};

    Solution s;
    s.minimumTotal(in);

    return 0;
}
