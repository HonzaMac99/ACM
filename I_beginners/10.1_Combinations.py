import math


def nCr(n, m):
    f = math.factorial
    return f(n) / f(m) / f(n-m)


n = m = 100

while True:
    params = list(map(int, input().split()))
    n = params[0]
    m = params[1]
    if n == 0:
        break
    print(n, "things taken", m, "at a time is", round(nCr(n, m)), "exactly.")
