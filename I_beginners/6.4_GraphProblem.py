mem = []
for i in range(77):
    mem.append(0)

mem[1] = 1
mem[2] = 2
mem[3] = 2

last = 3

while True:
    try:
        length = int(input())
        if mem[length] == 0:
            for i in range(last+1, length+1):
                mem[i] = mem[i-2] + mem[i-3]
            last = length
        print(mem[length])
    except EOFError:
        exit(0)
