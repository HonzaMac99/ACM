import math
from queue import PriorityQueue

def makePrimes(n):

    primes = []
    for i in range(n+1):
        primes.append(1)

    primes[0] = primes[1] = 0
    mul_p = 0

    for p in range(2, int(math.sqrt(n))+1):
        if primes[p] == 1:
            mul_p = p*p
            while mul_p <= n:
                primes[mul_p] = 0
                mul_p += p

    # primes_n = []
    # for i in range(len(primes)):
    #     if primes[i] == 1:
    #         primes_n.append(i)
    return primes


def get_num_arr(num):
    num_arr = [0, 0, 0, 0]
    rest = 0
    for i in range(4):
        num_arr[i] = (num - rest) // 10**(3-i)
        rest += num_arr[i] * 10**(3-i)
    # print(num_arr)
    return num_arr


def get_num(arr):
    num = 0
    for i in range(4):
        num += 10**i * arr[3-i]
    return num


primes = makePrimes(10001)

n = int(input())

for i in range(n):
    start_num, end_num = list(map(int, input().split()))
    path_len = 0

    q = PriorityQueue()
    q.put([0, start_num])
    visited = {}
    found = False
    while not q.empty() and not found:
        path_len, cur_num = q.get()
        if cur_num in visited:
            continue
        visited[cur_num] = True

        if cur_num == end_num:
            found = True
            break

        cur_num_arr = get_num_arr(cur_num)
        for i in range(4):
            for j in range(1, 10):
                new_num_arr = cur_num_arr.copy()
                new_num_arr[i] = (new_num_arr[i] + j) % 10
                if i == 0 and new_num_arr[i] == 0:
                    continue
                new_num = get_num(new_num_arr)
                if primes[new_num] and new_num not in visited:
                    q.put([path_len+1, new_num])
    if not found:
        print("impossible")
    else:
        print(path_len)
