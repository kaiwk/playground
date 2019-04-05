def solve(cells):
    n = len(cells)
    dp = [[0] * n for i in range(n)]
    dp[0][0] = cells[0][0]


    return dp

T = int(input())
for _ in range(T):
    n = int(input())
    arr = [int(i) for i in input().strip().split()]
    cells = []

    for i in range(n):
        tmp = []
        for j in range(n):
            tmp.append(arr[i*n+j])
        cells.append(tmp)

    print(solve(cells))
