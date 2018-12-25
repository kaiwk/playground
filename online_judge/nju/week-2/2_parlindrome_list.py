while True:
    try:
        arr = [i for i in input().split()]
        n = int(arr[0])
        arr = arr[1:]
        s = 0
        e = n-1
        while s < e and arr[s] == arr[e]:
            s += 1
            e -= 1

        if s >= e:
            print('true')
        else:
            print('false')
    except EOFError:
        break
