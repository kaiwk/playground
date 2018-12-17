# f = open('./input.txt')
# arr = [int(x) for x in f.readline().split()]
# beg, end = [int(x) for x in f.readline().split()]
# k = int(f.readline())

# solution 1

ARR = [int(x) for x in input().split()]
BEG, END = [int(x) for x in input().split()]
K = int(input())

def range_k_smallest(arr, beg, end, k):
    return k_smallest(arr[beg-1:end], k-1)

def part(arr, low, high):
    if low >= high:
        return low
    pivot = arr[high]
    i = low
    for j in range(low, high+1):
        if arr[j] < pivot:
            arr[i], arr[j] = arr[j], arr[i]
            i += 1
    arr[i], arr[high] = arr[high], arr[i]
    return i

def k_smallest(arr, k):
    ix = part(arr, 0, len(arr)-1)

    if k < ix:
        return k_smallest(arr[:ix], k)

    if k > ix:
        return k_smallest(arr[ix+1:], ix-k)

    return arr[ix]

# print(range_k_smallest(ARR, BEG, END, K))

# solution 2
def range_k_smallest2(arr, beg, end, k):
    return sorted(arr[beg-1:end])[k-1]

print(range_k_smallest2(ARR, BEG, END, K))
