f = open('./input.txt')
arr = [int(x) for x in f.readline().split()]
n = int(f.readline())

arr = [int(x) for x in input().split()]
n = int(input())

def two_sum(arr, target):
    if not arr:
        return 0
    res = 0
    complete = dict()
    for i, e in enumerate(arr):
        comp = target - e
        if e in complete:
            res += 1
        complete[comp] = i
    return res


print(two_sum(arr, n))
