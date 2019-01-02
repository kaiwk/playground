"""
# Definition for a Node.
class Node(object):
    def __init__(self, val, children):
        self.val = val
        self.children = children
"""
class Solution(object):
    def postorder(self, root):
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

        for c in root.children:
            self.dfs(c, res)

        res.append(root.val)


# Solution2
class Solution2(object):

    def postorder(self, root):
        if root is None:
            return []

        res = []
        stack = [root]
        visited = set()

        while len(stack) != 0:
            node = stack.pop()

            if node.children and node not in visited:
                visited.add(node)
                stack.append(node)
                for c in node.children[::-1]:
                    stack.append(c)
            else:
                res.append(node.val)

        return res
