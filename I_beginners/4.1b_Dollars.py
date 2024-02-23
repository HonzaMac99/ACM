# dynamic, bottom up
coins = [0.05, 0.10, 0.20, 0.50, 1.00, 2.00, 5.00, 10.00, 20.00, 50.00, 100.00]
mem = []
for i in range(6001):
    tmp = []
    for j in range(len(coins)):
        tmp.append(0)
    mem.append(tmp)

mem[0][0] = 1
last = 1

while True:
    cash = float(input())
    index = round(cash*20)
    count = 0

    if cash == 0.0:
        break
    elif mem[index][0] != 0:
        for i in range(len(coins)):
            count += mem[index][i]
    else:
        for i in range(last, index+1):
            curCash = i/20
            j = 0
            while j < len(coins) and coins[j] <= curCash:
                for k in range(j+1):
                    mem[i][j] += mem[round((curCash - coins[j])*20)][k]
                j += 1
            # print(mem[i])
            last += 1
        for i in range(len(coins)):
            count += mem[index][i]

    print(str("{:.2f}".format(cash)).rjust(6), str(count).rjust(16))
