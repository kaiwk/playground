def solve(A, B):
    n = len(A)
    m = len(B)

    path1, path2 = 0, 0
    i, j = 0, 0
    while i < n and j < m:
        if A[i] < B[j]:
            path1 += A[i]
            i += 1
        elif A[i] > B[j]:
            path2 += B[j]
            j += 1
        else:
            path1 += A[i]
            path2 += B[j]
            if path1 > path2:
                path2 = path1
            else:
                path1 = path2
            i += 1
            j += 1

    if A[i-1] == B[i-1]:
        if path1 > path2:
            path2 = path1
        else:
            path1 = path2

    while i < n:
        path1 += A[i]
        i += 1
    while j < m:
        path2 += B[j]
        j += 1

    return max(path1, path2)


T = int(input())
for _ in range(T):
    n, m = [int(i) for i in input().strip().split()]
    A = [int(i) for i in input().strip().split()]
    B = [int(i) for i in input().strip().split()]
    print(solve(A, B))
