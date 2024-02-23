cases = int(input())

for i in range(cases):
    divisible = 0
    params = list(map(int, input().split()))
    seqLen = params[0]
    divisor = params[1]

    sequence = list(map(int, input().split()))
    results = []

    for j in range(seqLen):
        tempRes = []
        for k in range(2**j):
            if j == 0:
                tempResult = sequence[j]
            elif k % 2 == 0:
                tempResult = results[j - 1][k // 2] + sequence[j]
            else:
                tempResult = results[j - 1][k // 2] - sequence[j]

            tempRes.append(tempResult)
        # print(tempRes)
        results.append(tempRes)

    for j in range(len(results[seqLen-1])):
        if results[seqLen-1][j] % divisor == 0:
            divisible = 1
            break
    if divisible:
        print("Divisible")
    else:
        print("Not divisible")





