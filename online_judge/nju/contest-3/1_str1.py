def solve(s):

    arr = [int(i) for i in list(s)]
    n = len(arr)
    res = 0

    for i in range(n):
        l = i
        r = i + 1
        for j in range(min(i, n - i) + 1):
            if l - j < 0 or r + j + 1 > n:
                continue
            lsum = sum(arr[l-j:l+1])
            rsum = sum(arr[r:r+j+1])
            # print(arr[l-j:l+1], arr[r:r+j+1])
            if lsum == rsum:
                res = max(2 * (j + 1), res)
    return res


T = int(input())

for _ in range(T):
    s = input()
    print(solve(s))
