mem = []

for i in range(301):
    tmp = []
    for j in range(301):
        tmp.append(0)
    mem.append(tmp)

mem[0][0] = 1

last = 1

while True:
    try:
        params = list(map(int, input().split()))

        price = params[0]
        count = 0

        # counts possible ways of paying for particular coins
        if mem[price][1] == 0:
            for i in range(last, price + 1):
                j = 1
                while j <= i:
                    if i-j == 0:
                        mem[i][j] += 1
                    else:
                        for k in range(1, j+1):
                            mem[i][j] += mem[i-j][k]
                    j += 1
                # print(mem[i])
                last += 1

        # counts the final number of possible ways of paying the price
        if len(params) == 1:
            for j in range(price+1):
                count += mem[price][j]

        elif len(params) == 2:
            highest = params[1]
            if highest > 300:
                highest = 300
            for j in range(highest+1):
                count += mem[price][j]

        elif len(params) == 3:
            lowest = params[1]
            if lowest > 300:
                lowest = 300
            highest = params[2]
            if highest > 300:
                highest = 300
            for j in range(lowest, highest+1):
                count += mem[price][j]

        print(count)
    except EOFError:
        exit(0)
