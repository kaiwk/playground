#include <vector>
#include <cstdio>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>> &matrix) {
        int n = matrix.size();
        for (int i = 0; i < n/2; ++i) {
            rotate_outer(matrix, i, n-2*i);
        }
    }
    void rotate_outer(vector<vector<int>> &m, int i, int n) {
        int e = i + n - 1;
        for (int j = i; j < e; ++j) {
            int k = j - i;
            int tmp = m[i][j];
            m[i][j] = m[e-k][i];
            log("m[%d][%d] = %d\n", i, j, m[i][j]);
            m[e-k][i] = m[e][e-k];
            m[e][e-k] = m[i+k][e];
            m[i+k][e] = tmp;
        }
    }
};

int main() {
    vector<vector<int>> m =
        {
         {1,2,3},
         {4,5,6},
         {7,8,9}
        };
    Solution s;
    s.rotate(m);
}
