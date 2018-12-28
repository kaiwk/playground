def area(x1, y1, x2, y2, x3, y3):
    return x1*y2 + x3*y1 + x2*y3 - x3*y2 - x2*y1 - x1*y3


def solve(pos, n):
    res = []
    for i in range(n):
        for j in range(i+1, n):
            all_left = True
            all_right = True
            x1 = pos[i][0]
            y1 = pos[i][1]
            x2 = pos[j][0]
            y2 = pos[j][1]
            for k in range(n):
                if k != i and k != j:
                    x3 = pos[k][0]
                    y3 = pos[k][1]

                    if area(x1, y1, x2, y2, x3, y3) < 0:
                        all_left = False
                    else:
                        all_right = False

            if all_left or all_right:
                if (x1, y1) not in res:
                    res.append((x1, y1))
                if (x2, y2) not in res:
                    res.append((x2, y2))

    res = sorted(res, key=lambda x: x[0])

    if res:
        print(res[0][0], res[0][1], end='')

    for i in range(1, len(res)):
        print(', ', res[i][0], res[i][1], end='')
    print()


t = int(input())
for _ in range(t):
    n = int(input())
    arr = [int(i) for i in input().split(' ')]
    pos = []

    for i in range(len(arr)):
        if i % 2 == 0:
            pos.append((arr[i], arr[i+1]))

    pos = sorted(pos, key=lambda x: x[0])
    solve(pos, n)
