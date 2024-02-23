cases = int(input())

for i in range(cases):
    divisible = 0
    params = list(map(int, input().split()))
    seqLen = params[0]
    divisor = params[1]

    sequence = []
    sequence2 = list(map(int, input().split()))
    for j in sequence2:
        j %= divisor
        if j != 0:
            sequence.append(j)
        else:
            seqLen -= 1

    results = []

    result = sequence[0]
    for j in range(1, seqLen):
        result += sequence[j]
    results.append(result)

    for j in range(seqLen-1):
        for k in range(2**j):
            result = results[k] - 2*sequence[seqLen-j-1]
            if result % divisor == 0:
                divisible = 1
                break
            results.append(result)

        if divisible:
            print("Divisible")
            break

    if not divisible:
        print("Not divisible")
