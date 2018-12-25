def bubble_sort(arr, n):
    for i in range(n-1):
        for j in range(n-i-1):
            if arr[j] > arr[j+1]:
                tmp = arr[j+1]
                arr[j+1] = arr[j]
                arr[j] = tmp


def print_arr(arr, n):
    print(arr[0], end='')
    for i in range(1, n):
        print('', arr[i], end='')
    print()


while True:
    try:
        arr = [int(i) for i in input().strip().split()]
        n = int(arr[0])
        arr = arr[1:]
        bubble_sort(arr, n)
        print_arr(arr, n)
    except EOFError:
        break
