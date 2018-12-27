import sys

class Solution(object):
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        if x == 0:
            return 0

        low = 1
        high = sys.maxsize

        while True:

            mid = (high + low) // 2

            if mid > x // mid:
                high = mid - 1
            else:
                if mid + 1 > x // (mid + 1):
                    return mid
                low = mid + 1
