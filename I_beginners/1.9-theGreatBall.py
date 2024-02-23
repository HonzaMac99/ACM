cases = int(input())

for i in range(cases):
    persons = int(input())

    latest = 0
    times = [0] * 10000000

    for j in range(persons):
        array = list(map(int, input().split()))
        for k in range(array[0], array[1]):
            times[k] += 1
            if array[1] > latest:
                latest = array[1]

    highest = 0
    for j in range(1, latest):
        if times[j] > highest:
            highest = times[j]
    print(highest)
