def solve(arr, queries):
    res = []

    for q in queries:
        cnt = 0
        for e in arr:
            if e % q == 0:
                cnt += 1
        res.append(cnt)

    return res


T = int(input())

for _ in range(T):
    N, M = [int(i) for i in input().strip().split(' ')]
    arr = [int(i) for i in input().strip().split(' ')]
    queries = [int(i) for i in input().strip().split(' ')]
    print(' '.join(map(str, solve(arr, queries))))
