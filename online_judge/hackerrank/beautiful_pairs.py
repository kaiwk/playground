# -*- coding: utf-8 -*-

from collections import defaultdict

n = int(input())
a = [ int(x) for x in input().strip().split(' ') ]
b = [ int(x) for x in input().strip().split(' ') ]

m = defaultdict(int)

for i in a:
    m[i] += 1

for i in b:
    if m[i] > 0:
        m[i] -= 1

res = n

for i in m.values():
    if i > 0:
        res -= i

res += -1 if res == n else 1

print(res)
