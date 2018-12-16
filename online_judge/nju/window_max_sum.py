# f = open('./input.txt')
# arr = [int(x) for x in f.readline().split()]
# n = int(f.readline())

arr = [int(x) for x in input().split()]
n = int(input())

# print(arr)
# print(n)

s = 0
for i in range(0, len(arr)-n+1):
    s += max(arr[i:i+n])
print(s)
