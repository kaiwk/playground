def solve(arr, target):
    n = len(arr)
    i = n -1
    res = 0
    while target > 0 and i >= 0:
        target -= arr[i]
        res += 1
        while i >= 0 and arr[i] > target:
            i -= 1
    if target == 0:
        return res
    return -1

T = int(input())

for _ in range(T):
    n, target = [int(i) for i in input().strip().split()]
    arr = [int(i) for i in input().strip().split()]
    print(solve(arr, target))
