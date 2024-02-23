length = 1
while length != 0:
    length = int(input())
    possibilities = 0
    if length == 0:
        break
    elif length == 1:
        possibilities = 1
    elif length == 2:
        possibilities = 2
    else:
        prev1 = 1
        prev2 = 2
        for i in range(length-3):
            temp = prev2
            prev2 += prev1
            prev1 = temp
        possibilities = prev1 + prev2
    print(possibilities)
