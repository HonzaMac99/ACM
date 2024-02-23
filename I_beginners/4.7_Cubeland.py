CubeCoins = 22
mem = []
for i in range(10001):
    tmp = []
    for j in range(CubeCoins):
        tmp.append(0)
    mem.append(tmp)

# 1 is helping constant
mem[0][1] = 1

last = 1

while True:
    try:
        price = int(input())
        count = 0

        if mem[price][0] != 0:
            for j in range(CubeCoins):
                count += mem[price][j]
            print(count)
        else:
            for i in range(last, price + 1):

                j = 1
                while j <= CubeCoins and j**3 <= i:
                    for k in range(1, j + 1):
                        mem[i][j] += mem[i-j**3][k]

                    j += 1
                # print(i, mem[i])
                last += 1

            for j in range(CubeCoins):
                count += mem[price][j]
            print(count)

    except EOFError:
        exit(0)
