class Solution(object):

    def __init__(self):
        self.res = []

    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        self.dfs(nums, [], 0)
        return self.res

    def dfs(self, nums, subset, i):

        if i == len(nums):
            if subset not in self.res:
                self.res.append(subset)
            return

        self.dfs(nums, subset, i+1)
        self.dfs(nums, subset+[nums[i]], i+1)
