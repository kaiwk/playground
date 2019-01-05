class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        res = []
        self.dfs(n, n, '', res)
        return res

    def dfs(self, l, r, path, res):
        if l > r:
            return

        if l == 0 and r == 0:
            res.append(path)

        if l > 0:
            self.dfs(l-1, r, path + '(', res)
        if r > 0:
            self.dfs(l, r-1, path + ')', res)
