class Solution(object):
    def hammingDistance(self, x, y):
        """
        :type x: int
        :type y: int
        :rtype: int
        """
        d = 0
        while x != 0 or y != 0:
            if x % 2 != y % 2:
                d += 1
            if x != 0:
                x >>= 1
            if y != 0:
                y >>= 1
        return d
