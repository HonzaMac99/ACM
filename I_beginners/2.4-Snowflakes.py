cases = int(input())

for i in range(cases):
    samples = int(input())
    snowflakes = []
    first = 0
    last = 0
    maxCount = 0
    for j in range(samples):
        snowflake = int(input())
        for k in range(first, last):
            if snowflake == snowflakes[k]:
                if (last-first) > maxCount:
                    maxCount = (last-first)
                first += k+1
                break
        snowflakes.append(snowflake)
        last += 1
        #print(first, last, snowflakes)
    if (last-first) > maxCount:
        maxCount = (last-first)
    print(maxCount)
