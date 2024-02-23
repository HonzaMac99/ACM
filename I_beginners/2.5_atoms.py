cases = int(input())

for i in range(cases):
    numbers = list(map(int, input().split()))
    time = 0
    atoms = numbers[0]
    while atoms*numbers[1] <= numbers[2]:
        atoms *= numbers[1]
        time += 1
    print(time)
