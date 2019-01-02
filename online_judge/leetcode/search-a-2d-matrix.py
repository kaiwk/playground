class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        l = 0
        r = len(matrix) - 1

        if r == -1 or len(matrix[0]) == 0:
            return False

        row = -1
        while l <= r:
            mid = (l + r) // 2
            if target < matrix[mid][0]:
                r = mid - 1
            else:
                if mid == len(matrix) - 1 or target < matrix[mid+1][0]:
                    row = mid
                    break
                else:
                    l = mid + 1

        if row == -1:
            return False

        l = 0
        r = len(matrix[0]) - 1
        col = -1
        while l <= r:
            mid = (l + r) // 2
            if target < matrix[row][mid]:
                r = mid - 1
            elif target > matrix[row][mid]:
                l = mid + 1
            else:
                col = mid
                break

        if col == -1:
            return False

        return True
