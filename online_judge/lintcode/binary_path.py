class Solution(object):

    def binaryTreePaths(self, root):

        if root is None:
            return []

        ret = []
        self.helper(root, '', ret)
        return ret

    def helper(self, root, path, ret):
        if root is None:
            return
        path = path + '->' + str(root.val)
        if root.left is None and root.right is None:
            ret.append(path[2:])
        else:
            if root.left:
                self.helper(root.left, str(path), ret)
            if root.right:
                self.helper(root.right, str(path), ret)
