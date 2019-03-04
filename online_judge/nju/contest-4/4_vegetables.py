def solve(n, veges):
    dp = [[0] * 3 for _ in range(n)]
    dp[0][0] = veges[0][0]
    dp[0][1] = veges[0][1]
    dp[0][2] = veges[0][2]
    for i in range(1, n):
        dp[i][0] = veges[i][0] + min(dp[i-1][1], dp[i-1][2])
        dp[i][1] = veges[i][1] + min(dp[i-1][0], dp[i-1][2])
        dp[i][2] = veges[i][2] + min(dp[i-1][0], dp[i-1][1])

    return min(dp[n-1][0], dp[n-1][1], dp[n-1][2])



T = int(input())
for _ in range(T):
    n = int(input())
    veges = []
    for i in range(n):
        veges.append([int(i) for i in input().strip().split()])

    print(solve(n, veges))
