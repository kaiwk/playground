class Solution(object):
    def sortArrayByParity(self, A):
        """
        :type A: List[int]
        :rtype: List[int]
        """
        i = 0
        n = len(A)

        for j in range(n):
            if A[j] % 2 == 0:
                A[i], A[j] = A[j], A[i]
                i += 1

        return A
