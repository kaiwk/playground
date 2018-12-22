import sys

class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        dp = nums
        res = nums[0]
        for i in range(1, n):
            dp[i] = max(dp[i-1] + nums[i], dp[i])
            res = max(res, dp[i])

        return res
