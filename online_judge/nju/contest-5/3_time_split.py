def solve(arr1, arr2, n):
    arr = list(zip(arr1, arr2))
    arr.sort(key=lambda x: x[1])

    res = 0
    for i in range(1, n):
        if arr[i][0] <= arr[i-1][1]:
            res += 1
    return res


T = int(input())
for _ in range(T):
    n = int(input())
    arr1 = [int(i) for i in input().strip().split()]
    arr2 = [int(i) for i in input().strip().split()]
    print(solve(arr1, arr2, n))
