cases = int(input())

for i in range(cases):
    n = int(input())
    fives = 0
    divisor = 5
    while divisor <= n:
        fives += n // divisor
        divisor *= 5
    print(fives)
# number of fives in the prime division of the n factorial
# represents the total number of zeros of the result
