tests = int(input())

for i in range(tests):
    n = int(input())

    count = 2**(n-1)

    if n != 1:
        ones = 2**(n-1)+2**(n-2)*(n-1)
    else:
        ones = 1

    print(count, ones)


