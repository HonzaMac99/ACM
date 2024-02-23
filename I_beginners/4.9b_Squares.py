mem = []
for i in range(10001):
    mem.append(0)
mem[1] = 1
last = 2

cases = int(input())

for i in range(cases):
    n = int(input())
    if mem[n] != 0:
        print(mem[n])
    else:
        for j in range(last, n+1):
            minPos = 0
            k = 1
            # print(j, end=" ")
            while k**2 <= j:
                if minPos == 0 or mem[j-k**2] + 1 < minPos:
                    minPos = mem[j-k**2] + 1
                    # print("-->", minPos, end=" ")
                k += 1
            # print("")
            mem[j] = minPos
            last += 1
        print(mem[n])
