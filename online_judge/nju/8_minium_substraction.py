f = open('./input.txt')
a = [int(x) for x in f.readline().split()]
b = [int(x) for x in f.readline().split()]

# a = [int(x) for x in input().split()]
# b = [int(x) for x in input().split()]

len_a = len(a)
len_b = len(b)

for i in range(len_a):
    for j in range(len_b):
        tmp = abs(sum(a) - sum(b))
        a[i], b[j] = b[j], a[i]
        if (abs(sum(a) - sum(b))) > tmp:
            a[i], b[j] = b[j], a[i]

print(abs(sum(a) - sum(b)))
