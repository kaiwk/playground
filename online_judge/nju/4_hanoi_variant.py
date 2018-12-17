def hanoi(n):
    """
    0,1,2,3
    A, B, C, A -> C
    """
    count = 0
    init = [i for i in range(1, n+1)] # [1,2]

    hist = [[init, [], []]]

    state = [init, [], []]

    while state != [[], [], init]:
        a, b, c = state[0], state[1], state[2]

        if ((a and not b) or (a and b and a[0] < b[0])) and [a[1:], [a[0]]+b, c] not in hist:
            state = [a[1:], [a[0]]+b, c]
            hist.append(state)
        elif ((b and not a) or (b and a and b[0] < a[0])) and [[b[0]]+a, b[1:], c] not in hist:
            state = [[b[0]]+a, b[1:], c]
            hist.append(state)
        elif ((b and not c) or (b and c and b[0] < c[0])) and [a, b[1:], [b[0]]+c] not in hist:
            state = [a, b[1:], [b[0]]+c]
            hist.append(state)
        elif ((c and not b) or (c and b and c[0] < b[0])) and [a, [c[0]]+b, c[1:]] not in hist:
            state = [a, [c[0]]+b, c[1:]]
            hist.append(state)
        count += 1

    return count


N = int(input())
print(hanoi(N))

# solution 2

N = int(input())

def hanoi2(n):
    if n == 1:
        return 2
    if n == 2:
        return 8
    return 3*hanoi2(n-1) + 2

print(hanoi2(N))
