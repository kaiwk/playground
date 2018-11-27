#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> d(m, vector<int>(n));
        d[0][0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i >= 1) {
                    d[i][j] += d[i-1][j];
                }
                if (j >= 1) {
                    d[i][j] += d[i][j-1];
                }
            }
        }
        return d[m-1][n-1];
    }
};
