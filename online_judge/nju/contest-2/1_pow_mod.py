# f = open('input.txt')
# n = int(f.readline().strip())

n = int(input().strip())

for _ in range(n):
    # a, b, c = [int(i) for i in f.readline().strip().split(' ')]
    a, b, c = [int(i) for i in input().strip().split(' ')]
    print(pow(a, b) % c)
