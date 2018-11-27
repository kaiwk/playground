class TreeNode(object):
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None

class Solution(object):
    def binaryTreePathSum(self, root, target):
        # @param {TreeNode} root the root of binary tree
        # @param {int} target an integer
        # @return {int[][]} all valid paths
        if root is None:
            return []

        ret = []
        self.dfs(root, [], ret, target)

        return ret


    def dfs(self, root, path, paths, target):

        path.append(root.val)

        if root.left is None and root.right is None:
            if target == sum(path):
                paths.append(path)

        if root.left:
            self.dfs(root.left, list(path), paths, target)
        if root.right:
            self.dfs(root.right, list(path), paths, target)



t1 = TreeNode(1)
t2 = TreeNode(2)
t3 = TreeNode(4)
t4 = TreeNode(2)
t5 = TreeNode(3)
t1.left = t2
t1.right = t3
t2.left = t4
t2.right = t5

print(Solution().binaryTreePathSum(t1, 5))
