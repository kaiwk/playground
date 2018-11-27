#!/usr/bin/env python
# -*- coding: utf-8 -*-

n = int(input().strip())
arr = [int(arr_temp) for arr_temp in input().strip().split(' ')]

res = 0
for i in arr:
    res += i

print(res)
