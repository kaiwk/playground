#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> d(m, vector<int>(n, 0));

        d[0][0] = obstacleGrid[0][0] == 0 ? 1 : 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) continue;
                if (i >= 1 && obstacleGrid[i-1][j] == 0) {
                    d[i][j] += d[i-1][j];
                }
                if (j >= 1 && obstacleGrid[i][j-1] == 0) {
                    d[i][j] += d[i][j-1];
                }
            }
        }
        return d[m-1][n-1];
    }
};
