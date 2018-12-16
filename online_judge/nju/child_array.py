# f = open('./input.txt')
# arr = [int(x) for x in f.readline().split()]
# num = int(f.readline())

arr = [int(x) for x in input().split()]
num = int(input())


# print(arr)
# print(num)

narr = len(arr)
i = 0
j = 1
min_ix = 0
max_ix = 0
res = 0

hist = list()

while i < narr:
    while j < narr:
        max_ix = arr.index(max(arr[i:j+1]))
        min_ix = arr.index(min(arr[i:j+1]))
        if arr[max_ix] - arr[min_ix] > num:
            break
        j += 1

    for ix in range(i, j):
        if arr[ix:j] not in hist:
            hist.append(arr[ix:j])
        if arr[i:i+j-ix] not in hist:
            hist.append(arr[i:i+j-ix])
    i += 1

print(hist)
print(len(hist))
