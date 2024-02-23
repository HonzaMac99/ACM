# bottom up
coins = [100.00, 50.00, 20.00, 10.00, 5.00, 2.00, 1.00, 0.50, 0.20, 0.10, 0.05]
mem = []
for i in range(6000):
    mem.append(0)


def combinations(cash, count, maxCoin):
    cash = round(cash, 2)
    # print(cash, end="  ")
    if maxCoin >= len(coins) or cash - coins[maxCoin] < 0:
        return count
    elif cash - coins[maxCoin] == 0:
        # print("[ ", coins[maxCoin], " ]")
        return count + 1
    else:
        for j in range(maxCoin, len(coins)):
            count = combinations(cash - coins[maxCoin], count, j)
        return count


while True:
    cash = float(input())
    count = 0
    if cash == 0.0:
        break
    else:
        for i in range(len(coins)):
            count = combinations(cash, count, i)
    print("")
    print(str(cash).rjust(6), str(count).rjust(17))

