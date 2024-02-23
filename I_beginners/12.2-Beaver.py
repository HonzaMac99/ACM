import math
pi = 3.141592653589793


while True:
    params = list(map(float, input().split()))
    if params[0] == params[1] == 0:
        break
    D = params[0]
    V = params[1]
    up = D
    down = 0
    d = D/2
    while pi*(D - d)**3/12 + pi*d*(D - d)/2 != V:
        print(pi*(D - d)**3/12 + pi*d*(D - d)/2, V)
        if pi*(D - d)**3/12 + pi*d*(D - d)/2 > V:
            down = d
        else:
            up = d
        if round(d, 4) == round((up+down)/2, 4):
            break
        d = (up+down)/2

    print("{res:.3f}".format(res=round(d, 3)))
