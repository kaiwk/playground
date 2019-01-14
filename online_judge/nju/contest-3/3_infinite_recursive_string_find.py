def make_string(s, step):
    res = s
    for i in range(step):
        res = res + '$' * (i + 1) + res[::-1]
    return res


all_s = make_string('12345', 20)

T = int(input())
for _ in range(T):
    pos = int(input())
    print(all_s[pos-1])
