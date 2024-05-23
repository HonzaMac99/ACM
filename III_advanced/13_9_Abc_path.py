import numpy as np

count = 1
while True:
    n_rows, n_cols = list(map(int, input().split()))
    if (n_rows + n_cols) == 0:
        break

    table = np.zeros((n_rows, n_cols), dtype=int)
    score = np.ones_like(table)
    for i in range(n_rows):
         table[i] = [ord(el) for el in list(input())]

    for chr in range(ord('B'), ord('Z')+1):
        poses_y, poses_x = np.where(table == chr)
        for x, y in zip(poses_x, poses_y):
            patch_chr = table[max(0, y-1):min(n_rows, y+2), max(0, x-1):min(n_cols, x+2)]
            patch_s   = score[max(0, y-1):min(n_rows, y+2), max(0, x-1):min(n_cols, x+2)]
            mask = (patch_chr == chr-1)
            score[y, x] += np.max(patch_s*mask)

    res = np.max(score)
    print(f"Case {count}: {res}")
    count += 1



