#!/usr/bin/env python
# -*- coding: utf-8 -*-

n = int(input().strip())

a = []

for a_i in range(n):
    a_tmp = [int(a_tmp) for a_tmp in input().strip().split(' ')]
    a.append(a_tmp)

res1 = 0
res2 = 0

for i in range(n):
    res1 += a[i][i]
    res2 += a[i][n - i - 1]

print(abs(res1 - res2))
