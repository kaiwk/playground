# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):

    def __init__(self):
        self.total = 0

    def sumNumbers(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root is None:
            return 0

        self.dfs(root, 0)
        return self.total

    def dfs(self, root, s):
        if root is None:
            return

        s = s * 10 + root.val
        if root.left is None and root.right is None:
            self.total += s
            return

        self.dfs(root.left, s)
        self.dfs(root.right, s)
