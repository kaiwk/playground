#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        // initialize
        for (int i = 0; i < n; ++i) {
            vector<string> vs = vector<string>(n, string(n, '.'));
        }
        return res;
    }

    bool canPlace(vector<string> &vs, int x, int y) {
        int n = vs.size();
        for (int i = 0; i < n; ++i) {
            // horizontal or vertical
            if ((vs[x][i] == 'Q' && i != y) || (vs[i][y] == 'Q' && i != x)) {
                return false;
            }

            // anti diagonal
            if (x+i < n && y+i < n && vs[x+i][y+i] == 'Q') return false;
            if (x-i >= 0 && y-i >= 0 && vs[x-i][y-i] == 'Q') return false;

            // diagonal
            if (x-i >= 0 && y+i < n && vs[x-i][y+i] == 'Q') return false;
            if (x+i < n && y-i >=0 && vs[x+i][y-i] == 'Q') return false;
        }
        return true;
    }

    void dfs() {}
};
