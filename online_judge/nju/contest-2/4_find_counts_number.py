def count_divisors(num):
    cnt = 0
    sqrt = int(num ** 0.5)
    for x in range(1, sqrt + 1):
        if num % x == 0:
            cnt += 1
    if sqrt ** 2 == num:
        return cnt * 2 - 1
    return cnt * 2


def is_prime(num):
    if count_divisors(num) == 2:
        return True
    return False


def calPrime(n):
    primes = []
    n += 1
    mask = [0] * n
    max_val = int(n ** .5) + 1

    for i in range(3, n, 2):
        if not mask[i]:
            primes.append(i)

            if i < max_val:
                for j in range(i * i, n, i):
                    mask[j] = 1
    if n >= 2:
        primes.insert(0, 2)
    return primes


def solve():
    prime_list = calPrime(1000000)
    n = len(prime_list)
    t = int(input())

    for _ in range(t):
        N = int(input())
        cnt = 0
        for i in range(n):
            a = prime_list[i]
            for j in range(i+1, n):
                b = prime_list[j]
                if (a ** 2) * (b ** 2) < N:
                    cnt += 1
                else:
                    break
            if a ** 4 >= N:
                break

        for i in prime_list:
            if i ** 8 < N:
                cnt += 1
            else:
                break

        print(cnt)

solve()
