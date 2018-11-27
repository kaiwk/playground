"""
Definition of TreeNode:
"""

class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None


class Solution:
    """
    @param root: The root of binary tree.
    @return: Level order in a list of lists of integers
    """
    def levelOrder(self, root):

        if root is None:
            return []

        ret = [[]]
        self.helper(root, 0, ret)
        return ret

    def helper(self, root, level, ret):
        if root is None:
            return
        if len(ret)-1 < level:
            ret.append([])
        ret[level].append(root.val)
        self.helper(root.left, level+1, ret)
        self.helper(root.right, level+1, ret)

class Solution2(object):

    def levelOrder(self, root):

        if root is None:
            return []

        ret = []
        levelNodes = []
        queue = [root, None]

        while queue:
            cur = queue.pop(0)
            if cur:
                levelNodes.append(cur.val)
                if cur.left:
                    queue.append(cur.left)
                if cur.right:
                    queue.append(cur.right)
            else:
                ret.append(levelNodes)
                levelNodes = []
                if queue:
                    queue.append(None)

        return ret

class Solution3(object):

    def levelOrder(self, root):

        if root is None:
            return []

        ret = []
        queue = [root]

        while queue:
            levelNodes = []
            size = len(queue)
            for _ in range(size):
                node = queue.pop(0)
                levelNodes.append(node.val)
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            ret.append(levelNodes)
        return ret


  #   3
  #  / \
  # 9  20
  #   /  \
  #  15   7

n1 = TreeNode(3)
n2 = TreeNode(9)
n3 = TreeNode(20)
n4 = TreeNode(15)
n5 = TreeNode(7)
n1.left = n2
n1.right = n3
n3.left = n4
n3.right = n5

print(Solution3().levelOrder(n1))
