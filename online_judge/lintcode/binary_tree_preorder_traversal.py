class Solution:

    def preorderTraversal(self, root):
        if root is None:
            return []
        ret = []
        self.helper(root, ret)
        return ret

    def helper(self, root, ret):
        if root is None:
            return
        ret.append(root.val)
        if root.left:
            self.helper(root.left, ret)
        if root.right:
            self.helper(root.right, ret)
