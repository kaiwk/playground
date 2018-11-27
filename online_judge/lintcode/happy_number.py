class Solution:
    # @param {int} n an integer
    # @return {boolean} true if this is a happy number or false
    def isHappy(self, n):
        return self.helper(n, set())

    def helper(self, n, dset):
        if n == 1:
            return True
        if n in dset:
            return False

        dset.add(n)
        digits = []

        while n != 0:
            digits.append(n%10)
            n //= 10

        msum = 0
        for d in digits:
            msum += pow(d, 2)
        return self.helper(msum, dset)
