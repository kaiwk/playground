from typing import List

class Solution:
    def largestSumOfAverages(self, A: List[int], K: int) -> float:
        n = len(A)
        p = [0] * (n+1)
        tmp = 0
        for i in range(n):
            tmp += A[i]
            p[i+1] = tmp

        def average(i, j):
            return (p[j+1] - p[i]) / (j + 1 - i)

        dp = [[0] * K for _ in range(n)]

        for i in range(n):
            dp[i][0] = average(0, i)

        for k in range(1, K):
            for i in range(1, n):
                for j in range(i, n):
                    dp[j][k] = max(dp[i-1][k-1] + average(i, j), dp[j][k])

        return dp[n-1][K-1]
