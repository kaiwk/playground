# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):

    def largestValues(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        res = []
        self.dfs(root, res, 0)
        return res

    def dfs(self, root, res, level):

        if root is None:
            return

        if len(res)-1 < level:
            res.append(root.val)
        else:
            res[level] = max(res[level], root.val)

        self.dfs(root.left, res, level+1)
        self.dfs(root.right, res, level+1)
