#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();

        int i = 0, j = 0;
        int mid = (m + n) / 2;

        nums1.push_back(INT_MAX);
        nums2.push_back(INT_MAX);

        bool odd = (m+n) % 2 == 1;
        int mid1 = 0, mid2 = 0;
        while (i + j <= mid) {
            mid2 = mid1;
            if (nums1[i] <= nums2[j]) {
                mid1 = nums1[i++];
            } else {
                mid1 = nums2[j++];
            }
        }
        if (odd) return mid1;
        else return (mid2 + mid1) / 2.0;
    }
};
