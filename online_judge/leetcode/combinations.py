class Solution(object):

    def __init__(self):
        self.res = []

    def combine(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[List[int]]
        """
        nums = [i for i in range(1, n+1)]
        self.dfs(nums, [], n, k, 0)
        return self.res

    def dfs(self, nums, c, n, k, start):
        if k == 0:
            self.res.append(c)
            return

        for j in range(start, n):
            self.dfs(nums, c + [nums[j]], n, k-1, j+1)
