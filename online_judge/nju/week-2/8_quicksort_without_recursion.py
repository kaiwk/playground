# recursive version
def quicksort(arr, low, high):
    if low < high:
        pivot_ix = partition(arr, low, high)
        quicksort(arr, low, pivot_ix-1)
        quicksort(arr, pivot_ix+1, high)


def partition(arr, low, high):
    if low >= high:
        return low
    pivot = arr[high]
    i = low
    for j in range(low, high):
        if arr[j] < pivot:
            arr[i], arr[j] = arr[j], arr[i]
            i += 1
    arr[i], arr[high] = arr[high], arr[i]
    return i
