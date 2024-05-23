import numpy as np

count = 1
while True:
    n = int(input())
    if n == 0:
        break

    score = np.zeros((n, 3))
    for i in range(n):
        score[i] = list(map(int, input().split()))

    score[0, 0] = np.inf
    score[0, 2] += score[0, 1]

    for i in range(1, n):
        score[i, 0] += min(score[i-1, 0], score[i-1, 1])
        score[i, 1] += min(score[i-1, 0], score[i-1, 1], score[i-1, 2], score[i, 0])
        score[i, 2] += min(score[i-1, 1], score[i-1, 2], score[i, 1])

    print(f"{count}. {int(score[n-1, 1])}")
    count += 1






