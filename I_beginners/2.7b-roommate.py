cases = int(input())

for i in range(cases):
    length = int(input())
    sequence = list(map(int, input().split()))
    count = 0
    for j in range(length):
        mysum = 0
        mysum += sequence[j]
        if mysum == 0:
            count += 1
        for k in range(j):
            if mysum == sequence[k]:
                count += 1

    print(count)
