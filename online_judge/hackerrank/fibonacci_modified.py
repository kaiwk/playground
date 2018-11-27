#!/usr/bin/env python
# -*- coding: utf-8 -*-


a, b, n = input().split(' ')

a = int(a)
b = int(b)
n = int(n)

dp = [0] * 100

dp[1] = a
dp[2] = b

for i in range(3, n+1):
    dp[i] = pow(dp[i-1], 2) + dp[i-2]

print(dp[n])
