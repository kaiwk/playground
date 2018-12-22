class Solution(object):
    def minSwap(self, A, B):
        """
        :type A: List[int]
        :type B: List[int]
        :rtype: int
        """
        n = len(A)
        swap = [n] * n
        no_swap = [n] * n
        swap[0] = 1
        no_swap[0] = 0
        for i in range(1, n):
            if A[i-1] < A[i] and B[i-1] < B[i]:
                swap[i] = swap[i-1] + 1
                no_swap[i] = no_swap[i-1]
            if A[i-1] < B[i] and B[i-1] < A[i]:
                swap[i] = min(swap[i], no_swap[i-1]+1)
                no_swap[i] = min(no_swap[i], swap[i-1])

        return min(swap[-1], no_swap[-1])
