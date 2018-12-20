import sys

class Solution(object):
    def nthUglyNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        u = [sys.maxsize] * n
        u[0] = 1
        i2 = 0
        i3 = 0
        i5 = 0
        for i in range(1, n):
            u2 = u[i2] * 2
            u3 = u[i3] * 3
            u5 = u[i5] * 5

            u[i] = min(u2, u3, u5)

            if u[i] == u2:
                i2 += 1
            if u[i] == u3:
                i3 += 1
            if u[i] == u5:
                i5 += 1

        return u[n-1]
