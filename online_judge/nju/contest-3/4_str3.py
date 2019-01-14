def solve(s, pat):
    n = len(s)
    m = len(pat)
    res = []
    for i in range(n):
        k = i
        for j in range(m):
            if k < n and s[k] == pat[j]:
                k += 1

        if k - i == m:
            res.append(i)

    return res

T = int(input())

for _ in range(T):
    s, pat = input().strip().split(',')
    print(' '.join(map(str, solve(s, pat))))
