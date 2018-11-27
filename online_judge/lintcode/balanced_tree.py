class Solution(object):

    def isBalanced(self, root):
        if root is None:
            return True
        diff = abs(self.treeDepth(root.left) - self.treeDepth(root.right))
        if diff > 1:
            return False
        return self.isBalanced(root.left) and self.isBalanced(root.right)

    def treeDepth(self, root):
        if root is None:
            return 0
        return max(self.treeDepth(root.left) + 1, self.treeDepth(root.right) + 1)
