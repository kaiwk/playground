#include <iostream>
#include <vector>
#include <algorithm>

#include "backward.cpp"

using namespace std;

class Solution {
private:
    int m, n;
    const int dx[4] = {1, -1, 0, 0};
    const int dy[4] = {0, 0, 1, -1};

    int dfs(vector<vector<int>> &matrix, vector<vector<int>> &dp, int i, int j) {
        if (dp[i][j]) return dp[i][j];
        int target = matrix[i][j];
        int ans = 1;
        for(int k = 0; k < 4; ++k) {
            int x = i + dx[k];
            int y = j + dy[k];
            if (x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] > target) {
                ans = max(ans, 1 + dfs(matrix, dp, x, y));
            }
        }
        dp[i][j] = ans;
        return dp[i][j];
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        m = matrix.size();
        n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int res = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                res = max(res, dfs(matrix, dp, i, j));
            }
        }
        return res;
    }
};

int main () {
    Solution s;
    // vector<vector<int>> in = {{2,8,6,0,4,14},{15,3,5,0,10,12},{10,13,14,5,11,16},{7,8,16,11,15,13},{19,10,7,13,0,11},{16,19,7,3,6,11}};
    vector<vector<int>> in = {
                              {2,  8,  6,  0,  4,  14},
                              {15, 3,  5,  0,  10, 12},
                              {10, 13, 14, 5,  11, 16},
                              {7,  8,  16, 11, 15, 13},
                              {19, 10, 7,  13, 0,  11},
                              {16, 19, 7,  3,  6,  11},
                              {7,  2,  5,  9,  0,  19},
                              {14, 11, 8,  8,  14, 11},
                              {4,  5,  10, 4,  2,  12}
    };
    cout << s.longestIncreasingPath(in) << endl;
}
