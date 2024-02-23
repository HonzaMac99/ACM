cases = int(input())

for i in range(cases):
    length = int(input())
    sequence = list(map(int, input().split()))
    count = 0
    for j in range(length):
        mysum = 0
        for k in range(j, length):
            mysum += sequence[k]
            if mysum == 0:
                # print(sequence[j:k+1])
                count += 1
    print(count)
