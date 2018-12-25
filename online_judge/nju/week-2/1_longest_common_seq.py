f = open('input.txt')
s1 = f.readline().strip()
s2 = f.readline().strip()

# s1 = input()
# s2 = input()
n1 = len(s1)
n2 = len(s2)
dp = [[0] * (n2+1) for _ in range(n1+1)]


def lcs():
    for i in range(1, n1+1):
        for j in range(1, n2+1):
            if s1[i-1] == s2[j-1]:
                dp[i][j] = dp[i-1][j-1] + 1
            else:
                dp[i][j] = max(dp[i][j-1], dp[i-1][j])
    return dp[n1][n2]


max_len = lcs()
res = list()


def trace_back(i, j, s):
    while i > 0 and j > 0:
        if s1[i-1] == s2[j-1]:
            s += s1[i-1]
            i -= 1
            j -= 1
        else:
            if dp[i-1][j] > dp[i][j-1]:
                i -= 1
            elif dp[i-1][j] < dp[i][j-1]:
                j -= 1
            else:
                trace_back(i-1, j, s)
                trace_back(i, j-1, s)
                return

    if len(s) == max_len and s[::-1] not in res:
        res.append(s[::-1])


trace_back(n1-1, n2-1, '')

for i in res:
    print(i)
