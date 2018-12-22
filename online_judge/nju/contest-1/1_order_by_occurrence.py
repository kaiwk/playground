T = int(input())

# f = open('input.txt')
# T = int(f.readline())

RANGE_N = 100

for _ in range(T):
    N = int(input())
    ARR = [int(i) for i in input().split()]

    # N = int(f.readline())
    # ARR = [int(i) for i in f.readline().split()]

    res = []
    ix = [0] * RANGE_N
    for e in ARR:
        ix[e] += 1

    for i in range(RANGE_N):
        cnt = max(ix)
        ind = ix.index(cnt)

        for j in range(cnt):
            res.append(ind)

        ix[ind] = 0

    for i in res:
        print(i, end=' ')
    print()
