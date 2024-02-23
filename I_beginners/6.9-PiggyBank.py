cases = int(input())

for i in range(cases):
    params = list(map(int, input().split()))
    pig_weight = params[1] - params[0]
    types = int(input())
    weights = []
    values = []
    for j in range(types):
        coin = list(map(int, input().split()))
        values.append(coin[0])
        weights.append(coin[1])
    print(weights)
    print(values)
    cur_weight = [[0 for x in range(pig_weight + 1)] for y in range(types + 1)]
    cur_val = [[0 for x in range(pig_weight + 1)] for y in range(types + 1)]

    for r in range(types + 1):
        for s in range(pig_weight + 1):
            if r == 0 or s == 0:
                cur_val[r][s] = 0
                cur_weight[r][s] = 0
            elif weights[r - 1] <= s:
                if values[r - 1] + cur_val[r - 1][s - weights[r - 1]] < cur_val[r - 1][s]:
                    cur_weight[r][s] = weights[r - 1] + cur_weight[r - 1][s - weights[r - 1]]
                    cur_val[r][s] = values[r - 1] + cur_val[r - 1][s - weights[r - 1]]
                else:
                    cur_weight[r][s] = cur_weight[r - 1][s]
                    cur_val[r][s] = cur_val[r - 1][s]
            else:
                cur_weight[r][s] = cur_weight[r - 1][s]
                cur_val[r][s] = cur_val[r - 1][s]

    # print(cur_val[types][pig_weight])
    for r in range(types + 1):
        print(cur_val[r])
    print("")
    for r in range(types + 1):
        print(cur_weight[r])
