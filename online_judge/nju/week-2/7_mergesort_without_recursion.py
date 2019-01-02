# recursion version
def mergesort(arr, low, high):
    if low < high:
        m = (low + high) // 2
        mergesort(arr, low, m)
        mergesort(arr, m+1, high)
        merge(arr, low, m, high)


def merge(arr, l, m, r):
    """
    L: arr[l, m]
    R: arr[m+1, r]
    """
    n1 = m-l+1
    n2 = r-m
    L = [0] * n1
    R = [0] * n2

    for i in range(n1):
        L[i] = arr[l+i]
    for i in range(n2):
        R[i] = arr[m+1+i]

    i = 0
    j = 0
    k = l
    while i < n1 and j < n2:
        if L[i] < R[j]:
            arr[k] = L[i]
            i += 1
        else:
            arr[k] = R[j]
            j += 1
        k += 1

    if i == n1:
        while j < n2:
            arr[k] = R[j]
            k += 1
            j += 1

    if j == n2:
        while i < n1:
            arr[k] = L[i]
            k += 1
            i += 1
