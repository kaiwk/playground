class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        if not candidates:
            return []
        candidates.sort()
        res = []
        self.dfs(candidates, target, 0, [], res)
        return res

    def dfs(self, nums, target, step, path, res):

        if target < 0:
            return
        if target == 0:
            res.append(path)
            return
        for i in range(step, len(nums)):
            if i > step and nums[i] == nums[i-1]:
                continue
            self.dfs(nums, target-nums[i], i + 1, path + [nums[i]], res)
