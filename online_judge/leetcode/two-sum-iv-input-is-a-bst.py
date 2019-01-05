class Solution:
    def findTarget(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: bool
        """
        return self.find(root, k, dict())

    def find(self, root, k, record):
        if root is None:
            return False

        if root.val in record:
            return True

        record[k - root.val] = root.val

        return self.find(root.left, k, record) or self.find(root.right, k, record)
