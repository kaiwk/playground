# f = open('./input.txt')
# arr = [int(x) for x in f.readline().split()]
# beg, end = [int(x) for x in f.readline().split()]
# k = int(f.readline())

arr = [int(x) for x in input().split()]
beg, end = [int(x) for x in input().split()]
k = int(input())

def range_k_smallest(arr, beg, end, k):
    return k_smallest(arr[beg-1:end], k-1)

def part(arr, low, high):
    if low >= high:
        return low
    pivot = arr[high]
    i = low
    for j, e in enumerate(a[low:high+1]):
        if arr[j] < pivot:
            arr[i], arr[j] = arr[j], arr[i]
            i += 1
    arr[i], arr[high] = arr[high], arr[i]
    return i

def k_smallest(arr, k):
    pivot = part(arr, 0, len(arr)-1)
    print(pivot)
    if k < pivot:
        pivot = part(arr, 0, pivot-1)
    elif k > pivot:
        pivot = part(arr, pivot+1, len(arr)-1)
    return arr[pivot]

print(range_k_smallest(arr, beg, end, k))
