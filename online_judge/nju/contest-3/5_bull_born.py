def solve(n):
    f1 = 1
    f2 = 0
    f = 0
    for i in range(n):
        f = f1 + f2
        f2 = f1
        f1 = f
    return f

T = int(input())

for _ in range(T):
    n = int(input())
    print(solve(n))
