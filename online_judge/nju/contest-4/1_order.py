def solve(n, x, y, X, Y):
    X, Y = (list(l) for l in zip(*sorted(zip(X, Y), key=lambda e: abs(e[0] - e[1]), reverse=True)))
    max_total = 0
    for i in range(n):
        if X[i] >= Y[i]:
            if x > 0:
                max_total += X[i]
                x -= 1
            elif y > 0:
                max_total += Y[i]
                y -= 1

        if X[i] < Y[i]:
            if y > 0:
                max_total += Y[i]
                y -= 1
            elif x > 0:
                max_total += X[i]
                x -= 1

    return max_total


T = int(input())
for _ in range(T):
    n, x, y = [int(i) for i in input().strip().split()]
    X = [int(i) for i in input().strip().split()]
    Y = [int(i) for i in input().strip().split()]
    print(solve(n, x, y, X, Y))
