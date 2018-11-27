#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        size_t i = 1;
        for(;i < A.size() && A[i-1] < A[i]; ++i) {}
        return i-1;
    }
};
