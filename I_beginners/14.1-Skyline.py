mem = []
skyline = []

for i in range(10001):
    mem.append(0)


while True:
    try:
        building = list(map(int, input().split()))
        for i in range(building[0], building[2]):
            if building[1] > mem[i]:
                mem[i] = building[1]

    except EOFError:
        cur_h = 0
        for i in range(len(mem)):
            if mem[i] > cur_h:
                skyline.append(i)
                skyline.append(mem[i])
                cur_h = mem[i]
            if mem[i] < cur_h:
                skyline.append(i)
                skyline.append(mem[i])
                cur_h = mem[i]
        for i in range(len(skyline)):
            if i < len(skyline) - 1:
                print(skyline[i], end=" ")
            else:
                print(skyline[i])
        exit(0)
