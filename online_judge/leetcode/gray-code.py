class Solution:
    def grayCode(self, n: int) -> List[int]:
        res = []
        res.append(0)
        self.dfs(n, 0, 1<<n, res)
        return res

    def dfs(self, n, cur, size, res):
        if len(res) == size:
            return
        for i in range(n):
            mask = 1 << i
            next_step = mask ^ cur
            if next_step not in res:
                res.append(next_step)
                self.dfs(n, next_step, size, res)
                if len(res) == size:
                    return
                res.remove(next_step)
