class Solution(object):
    def myPow(self, x, n):
        if n < 0:
            x = 1 / x
            n = abs(n)
        if x == 0:
            return 0
        if n == 0:
            return 1
        if n == 1:
            return x

        if n % 2 == 0:
            return self.myPow(x, n//2) * self.myPow(x, n//2)
        else:
            return self.myPow(x, n//2) * self.myPow(x, n//2) * x
