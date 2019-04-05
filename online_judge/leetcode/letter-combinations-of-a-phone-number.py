class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        mappings = [None, None,
                    "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]

        if not digits:
            return []

        res = []
        self.dfs(mappings, digits, 0, "", res)
        return res

    def dfs(self, mappings, digits, step, path, res):
        if len(digits) == len(path):
            res.append(path)
            return

        for c in mappings[int(digits[step])]:
            self.dfs(mappings, digits, step + 1, path + c, res)
