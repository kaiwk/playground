class Solution(object):

    def subarraySum(self, nums):
        if nums is None or len(nums) < 2:
            return [0, 0]
        n = len(nums)
        for i in range(n):
            msum = 0
            for j in range(i, n):
                msum += nums[j]
                if msum == 0:
                    return [i, j]
