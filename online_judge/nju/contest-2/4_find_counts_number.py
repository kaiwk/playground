# f = open('input.txt')
# t = int(f.readline())

# t = int(input())


# def count_divisors(num):
#     cnt = 0
#     sqrt = int(num ** 0.5)
#     for x in range(1, sqrt + 1):
#         if num % x == 0:
#             cnt += 1
#     if sqrt ** 2 == num:
#         return cnt * 2 - 1
#     return cnt * 2


def count_divisors(n):
    cnt = 0
    sqrt = int(n ** 0.5)
    for i in range(1, sqrt+1):
        if n % i == 0:
            if n // i == i:
                cnt += 1
            else:
                cnt += 2
    return cnt

# for _ in range(t):
#     # n = int(f.readline())
#     n = int(input())
#     cnt = 0
#     prime_list = get_prime_count(int(n ** 0.5))
#     prime_n = len(prime_list)
#     for i in range(prime_n):
#         for j in range(i+1, prime_n):
#             if (prime_list[i] ** 2) * (prime_list[j] ** 2) < n:
#                 cnt += 1
#     print(cnt)
