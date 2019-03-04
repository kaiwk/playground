def solve(n, arr):
    total = 0
    while arr:
        i = len(arr)-1
        total += arr[i]
        try:
            arr.remove(arr[i]-1)
        except ValueError:
            pass
        arr.pop()
    return total


T = int(input())
for _ in range(T):
    n = int(input())
    arr = [int(i) for i in input().strip().split()]
    print(solve(n, arr))
