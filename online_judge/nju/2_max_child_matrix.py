import copy

# f = open('./input.txt')
# arr = [[int(x) for x in row.split()] for row in f.readlines()]

arr = []
try:
    while True:
        e = [int(x) for x in input().split()]
        arr.append(e)
except EOFError:
    pass

w = 0
h = 0

index = copy.deepcopy(arr)

for i in range(len(arr)):
    for j in range(len(arr[0])):
        if j - 1 >= 0 and index[i][j] != 0:
            index[i][j] = index[i][j-1] + 1

# print(index)
res = 0
for i in range(len(arr)):
    for j in range(len(arr[0])):
        if index[i][j] == 0:
            continue

        up = i
        down = i
        while up >=0 and index[i][j] <= index[up][j]:
            up -= 1

        while down < len(arr) and index[i][j] <= index[down][j]:
            down += 1

        res = max(index[i][j]*(down-up-1), res)

print(res)
