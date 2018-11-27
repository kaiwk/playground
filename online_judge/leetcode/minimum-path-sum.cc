#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int d[m][n];

        d[0][0] = grid[0][0];
        for (int i = 1; i < m; ++i) {
            d[i][0] = d[i-1][0] + grid[i][0];
        }
        for (int j = 1; j < n; ++j) {
            d[0][j] = d[0][j-1] + grid[0][j];
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                d[i][j] = grid[i][j] + min(d[i-1][j], d[i][j-1]);
            }
        }
        return d[m-1][n-1];
    }
};
