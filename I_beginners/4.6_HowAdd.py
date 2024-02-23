mem = []

for i in range(101):
    temp = []
    for j in range(102):
        temp.append(0)
    mem.append(temp)

mem[0][0] = 1

lastNumCount = 1
lastNum = 0

while True:
    params = list(map(int, input().split()))
    number = params[0]
    numCount = params[1]

    if number == numCount == 0:
        break

    if mem[numCount][number] != 0 or numCount == 0:
        print(mem[numCount][number] % 1000000)
    else:

        for i in range(1, numCount+1):
            for j in range(0, number+1):
                # if i == 1, else:
                temp = 0
                for k in range(j+1):
                    temp += mem[i-1][k]
                mem[i][j] = temp

        print(mem[numCount][number] % 1000000)

    # for i in range(10):
    #     print("| ".rjust(3), end="")
    #     for j in range(10):
    #         print(str(mem[i][j]).rjust(3, "_"), end=" | ".rjust(3))
    #     print("")

