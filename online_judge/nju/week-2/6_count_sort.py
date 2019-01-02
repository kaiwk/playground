def count_sort(arr, n):
    m = max(arr)
    c = [0] * (m+1)

    for i in arr:
        c[i] += 1

    k = 0
    for i in range(m+1):
        for j in range(c[i]):
            arr[k] = i
            k += 1


def print_arr(arr, n):
    print(arr[0], end='')
    for i in range(1, n):
        print('', arr[i], end='')
    print()


while True:
    try:
        arr = [int(i) for i in input().strip().split(' ')]
        n = arr[0]
        arr = arr[1:]
        count_sort(arr, n)
        print_arr(arr, n)
    except EOFError:
        break
