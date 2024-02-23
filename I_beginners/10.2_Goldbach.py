import math


def makeOddPrimes(n):

    primes = []
    for i in range(n+1):
        primes.append(1)

    primes[0] = primes[1] = 0

    for p in range(2, int(math.sqrt(n))+1):
        if primes[p] == 1:
            mul_p = p*p
            while mul_p <= n:
                primes[mul_p] = 0
                mul_p += p
    primes_n = []
    for i in range(3, len(primes)):
        if primes[i] == 1:
            primes_n.append(i)
    return primes_n


primes = makeOddPrimes(1000000)
primes_set = set(primes)

while True:
    n = int(input())
    if n == 0:
        break
    i = 0
    while n-primes[i] not in primes_set and n-primes[i] >= primes[0]:
        # print(primes[i], "+", n-primes[i])
        i += 1
    if n-primes[i] in primes_set:
        print(n, "=", primes[i], "+", n - primes[i])
    else:
        print("Goldbach's conjecture is wrong.")
