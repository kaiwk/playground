class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        if not candidates:
            return []
        res = []
        candidates.sort()
        self.dfs(candidates, target, [], 0, res)
        return res

    def dfs(self, cand, target, path, step, res):
        if target < 0:
            return
        if target == 0:
            res.append(path)
            return
        for i in range(step, len(cand)):
            self.dfs(cand, target-cand[i], path + [cand[i]], i, res)
