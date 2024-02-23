import math


def catalan(n):
    f = math.factorial
    return f(2*n) / f(n+1) / f(n)


while True:
    try:
        n = int(input())
        print(int(catalan(n)))
    except ValueError:
        print("")
        continue
    except EOFError:
        exit(0)

