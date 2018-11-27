#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (size_t i = 0; i < nums.size(); ++i) {
            int s = pq.size();
            if (s < k) {
                pq.push(nums[i]);
            } else if (s >= k && nums[i] > pq.top()) {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
};

class Solution2 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        return findKth(nums, n-k, 0, n-1);
    }

    int findKth(vector<int>& nums, int k, int left, int right) {
        if (k >= 0 && k <= right-left+1) {

            // partition
            int pivot = nums[right], i = left;
            for (int j = left; j < right; ++j) {
                if (nums[j] <= pivot) {
                    swap(nums[j], nums[i]);
                    ++i;
                }
            }
            swap(nums[i], nums[right]);

            int pos = i;

            if (k == pos - left) {
                return nums[pos];
            } else if (k < pos - left) {
                return findKth(nums, k, left, pos-1);
            } else if (k > pos - left){
                return findKth(nums, k-pos+left-1, pos+1, right);
            }
        }
        return -1;
    }
};
