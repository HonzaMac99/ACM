import math


def makePrimes(n):

    primes = []
    for i in range(n+1):
        primes.append(1)

    primes[0] = primes[1] = 0
    mul_p = 0

    for p in range(2, int(math.sqrt(n))+1):
        if primes[p] == 1:
            mul_p = p*p
            while mul_p <= n:
                primes[mul_p] = 0
                mul_p += p

    return primes


def nCr(n,r):
    f = math.factorial
    return f(n) / f(r) / f(n-r)


primes = makePrimes(400)
for i in range(20):
    for j in range(20):
        print(primes[j + i*20 + 1], end=" ")
    print("")

print(int(nCr(100, 56)))



