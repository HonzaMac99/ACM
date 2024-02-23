cases = int(input())

for i in range(cases):
    params = list(map(int, input().split()))
    height = params[0]
    capacity = params[1]

    racks = []

    for j in range(height):
        rack = list(map(int, input().split()))
        units = 0
        for k in range(1, rack[0]+1):
            units += rack[k]
        racks.append(units)
    mem = [[0 for x in range(capacity + 1)] for y in range(height + 1)]
    for r in range(height + 1):
        for s in range(capacity + 1):
            if r == 0 or s == 0:
                mem[r][s] = 0
            elif racks[r - 1] <= s:
                if racks[r - 1] + mem[r - 1][s - racks[r - 1]] > mem[r-1][s]:
                    mem[r][s] = racks[r - 1] + mem[r - 1][s - racks[r - 1]]
                else:
                    mem[r][s] = mem[r-1][s]
            else:
                mem[r][s] = mem[r-1][s]

    print(mem[height][capacity])

    # for r in range(height + 1):
    #     print(mem[r])



