"""
# Definition for a Node.
class Node(object):
    def __init__(self, val, children):
        self.val = val
        self.children = children
"""
class Solution1(object):
    def preorder(self, root):
        """
        :type root: Node
        :rtype: List[int]
        """
        res = []
        self.dfs(root, res)
        return res

    def dfs(self, root, res):
        if root is None:
            return

        res.append(root.val)

        for c in root.children:
            self.dfs(c, res)


# Solution2
class Solution2(object):
    def preorder(self, root):

        if root is None:
            return []

        res = []
        stack = [root]

        while len(stack) != 0:
            node = stack.pop()
            res.append(node.val)
            for c in node.children[::-1]:
                stack.append(c)

        return res
