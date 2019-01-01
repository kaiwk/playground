class Solution:
    def singleNumber(self, nums):
        max_val = max(nums)

        m = dict()

        n = len(nums)
        for i in range(n):
            if nums[i] not in m:
                m[nums[i]] = 1
            else:
                m[nums[i]] += 1

        for k in m:
            if m[k] == 1:
                return k


class Solution2:
    def singleNumber(self, nums):
        result = 0
        n = len(nums)
        for i in range(n):
            result ^= nums[i]
        return result
