class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> dmax(n, 0);
        vector<int> dmin(n, 0);
        dmax[0] = nums[0];
        dmin[0] = nums[0];
        int res = dmax[0];
        for (int i = 1; i < n; ++i) {
            dmin[i] = min({nums[i], dmax[i-1] * nums[i], dmin[i-1] * nums[i]});
            dmax[i] = max({nums[i], dmax[i-1] * nums[i], dmin[i-1] * nums[i]});
            res = max(res, dmax[i]);
        }
        return res;
    }
};
