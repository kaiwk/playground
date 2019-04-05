# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findMode(self, root: TreeNode) -> List[int]:

        if root is None:
            return []

        count = {}
        self.dfs(root, count)
        max_val = max(count.values())

        res = [k for k, v in count.items() if v == max_val]

        return res

    def dfs(self, root, count):
        if root is None:
            return
        count[root.val] = count.get(root.val, 0) + 1
        self.dfs(root.left, count)
        self.dfs(root.right, count)
