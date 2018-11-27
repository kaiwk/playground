class Solution(object):

    def postorderTraversal(self, root):
        if root is None:
            return []

        ret = []
        self.helper(root, ret)
        return ret

    def helper(self, root, ret):

        if root is None:
            return

        if root.left:
            self.helper(root.left, ret)
        if root.right:
            self.helper(root.right, ret)

        ret.append(root.val)
