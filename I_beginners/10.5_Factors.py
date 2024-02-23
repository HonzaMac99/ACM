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

    primes_n = []
    for i in range(len(primes)):
        if primes[i] == 1:
            primes_n.append(i)
    return primes_n


primes = makePrimes(1000001)

while True:
    n = int(input())
    if n == 0:
        break
    factors = 0
    for i in range(len(primes)):
        if n % primes[i] == 0:
            factors += 1
    print(n, ":", factors)
