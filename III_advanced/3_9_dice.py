import math
import numpy as np

TEST = False
cases = 1 if TEST else int(input())

for i in range(cases):
    [n, k] = [100, 400] if TEST else list(map(int, input().split()))
    n_all_combs = pow(6, n)
    max_val = k  # n*6
    # val_combs = np.zeros(k+1, dtype=int)
    val_combs = np.zeros(n*6+1, dtype=int)

    if (k / 6) > n or (k / 1) < n:
        print(0)
        continue

    if n >= 1:
        idx = 1
        val_combs[idx:min(idx+6, k+1)] += 1

    # print(f"0: {val_combs}")
    for j in range(1, n):
        # comb_idxs = np.where(val_combs != 0)
        # val_combs_new = np.zeros(k+1, dtype=int)
        # for idx in comb_idxs[0]:
        #     val_combs_new[idx+1:min(idx+1+6, k+1)] += val_combs[idx]

        nonz_mask = (val_combs != 0).astype(int)
        val_combs += np.hstack((0, np.convolve(val_combs, np.ones(6))[:-6].astype(int))) - nonz_mask
        val_combs[val_combs < 0] = 0
        # print(f"{j}: {val_combs}")

    n_combs = val_combs[k]
    result = 100 * n_combs // n_all_combs
    # print(f"100 * {n_combs} / {n_all_combs} = {100 * n_combs // n_all_combs}")
    print(result)

