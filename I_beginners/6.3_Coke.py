cases = int(input())

for i in range(cases):

    params = list(map(int, input().split()))
    cokes = params[0]
    coins = params[1:]
    quantity = 0
    if cokes < coins[2]:
        quantity = cokes
        cokes = 0
    elif cokes < coins[1] + coins[2]:
        quantity += coins[2]
        cokes -= coins[2]
    else:
        need_fives = (cokes - coins[2]) - coins[1]
        if coins[2] >= need_fives:
            quantity += (coins[2] - need_fives) + 4*need_fives
            coins[1] += need_fives
        else:
            quantity += 4*coins[2]
            coins[1] += coins[2]
        cokes -= coins[2]

    if 2*cokes <= coins[1]:
        quantity += 2*cokes
    elif cokes <= coins[1]:
        quantity += 2*(coins[1] - cokes) + 4*(2*cokes - coins[1])
    else:
        quantity += 4*(coins[1]) + 8*(cokes - coins[1])

    print(quantity)
