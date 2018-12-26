class Solution(object):

    def __init__(self):
        self.memory = {}

    def findTargetSumWays(self, nums, S):
        """
        :type nums: List[int]
        :type S: int
        :rtype: int
        """
        n = len(nums)
        return self.dfs(nums, n, 0, S, 0)

    def dfs(self, nums, n, _sum, s, step):
        if step == n:
            if _sum == s:
                return 1
            return 0

        k = str(step) + '-' + str(_sum)

        if k in self.memory:
            return self.memory[k]

        add_cnt = self.dfs(nums, n, _sum+nums[step], s, step+1)
        minus_cnt = self.dfs(nums, n, _sum-nums[step], s, step+1)

        self.memory[k] = add_cnt + minus_cnt

        return add_cnt + minus_cnt
