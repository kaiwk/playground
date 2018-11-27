import sys

n = int(input().strip())

arr = [int(x) for x in input().strip().split(' ')]

cnt_pos = 0
cnt_neg = 0
cnt_zero = 0
cnt = len(arr)


for x in arr:
    if x > 0:
        cnt_pos += 1
    elif x == 0:
        cnt_zero += 1
    else:
        cnt_neg += 1

print("%.5f" % (cnt_pos / cnt))
print("%.5f" % (cnt_neg / cnt))
print("%.5f" % (cnt_zero / cnt))
