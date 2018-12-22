T = int(input())

# f = open('input.txt')
# T = int(f.readline())

for _ in range(T):
    N = int(input())
    ARR = [int(i) for i in input().split()]

    # N = int(f.readline())
    # ARR = [int(i) for i in f.readline().split()]

    cnt = 0
    for i in range(N):
        for j in range(i, N):
            if ARR[i] > ARR[j]:
                cnt += 1
    print(cnt)
