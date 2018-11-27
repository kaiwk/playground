#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sumA = accumulate(A.begin(), A.end(), 0);
        int sumB = accumulate(B.begin(), B.end(), 0);
        for (size_t i = 0; i < A.size(); ++i) {
            for (size_t j = 0; j < B.size(); ++j) {
                if (sumA - A[i] + B[j] == sumB - B[j] + A[i]) {
                    return {A[i], B[j]};
                }
            }
        }
        return {0, 0};
    }
};
