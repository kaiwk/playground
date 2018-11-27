#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> t;
        for (int i = 0; i <= rowIndex; ++i) {
            t.push_back(vector<int>(i+1, 1));
        }

        for (int i = 0; i <= rowIndex; ++i) {
            for (int j = 0; j < i; ++j) {
                if (i >= 1 && j >= 1) {
                    t[i][j] = t[i-1][j-1] + t[i-1][j];
                }
            }
        }

        return t[rowIndex];
    }
};
