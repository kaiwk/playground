class Solution(object):
    def transpose(self, A):
        """
        :type A: List[List[int]]
        :rtype: List[List[int]]
        """
        n = len(A)
        if n == 0:
            return []

        m = len(A[0])
        if m == 0:
            return []

        A_t = [[0] * n for _ in range(m)]

        for i in range(m):
            for j in range(n):
                A_t[i][j] = A[j][i]

        return A_t
