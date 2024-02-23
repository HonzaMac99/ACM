import math


def findDivisors(n):

    primes = []
    for i in range(n+1):
        primes.append(1)

    primes[0] = 0
    primes[1] = 1

    for p in range(3, int(math.sqrt(n))+3, 2):
        if primes[p] == 1:
            mul_p = p*p
            while mul_p <= n:
                if primes[mul_p] == 1:
                    primes[mul_p] = p
                mul_p += p

    return primes


divisors = findDivisors(100000000)

# for i in range(20):
#     for j in range(20):
#         if primes[j + i*20 + 1] == 1:
#             print(j + i*20 + 1, end=" ")
#         else:
#             print(primes[j + i*20 + 1], end=" ")
#     print("")

while True:
    n = int(input())
    if n == 0:
        break
    if n == 1:
        print(1)
    elif divisors[n] == 1:
        print(n)
    else:
        print(divisors[n])

