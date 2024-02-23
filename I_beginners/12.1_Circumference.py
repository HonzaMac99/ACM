import math
pi = 3.141592653589793


def power(x):
    return x*x


while True:
    try:
        coords = list(map(float, input().split()))
        middle = [0, 0]
        const = 2*(coords[0]*(coords[3] - coords[5])
                   + coords[2]*(coords[5] - coords[1])
                   + coords[4]*(coords[1] - coords[3]))

        middle[0] = ((power(coords[0]) + power(coords[1]))*(coords[3] - coords[5])
                     + (power(coords[2]) + power(coords[3]))*(coords[5] - coords[1])
                     + (power(coords[4]) + power(coords[5]))*(coords[1] - coords[3])) / const

        middle[1] = ((power(coords[0]) + power(coords[1])) * (coords[4] - coords[2])
                     + (power(coords[2]) + power(coords[3])) * (coords[0] - coords[4])
                     + (power(coords[4]) + power(coords[5])) * (coords[2] - coords[0])) / const
        # print(middle)
        radius = math.sqrt(power(coords[0] - middle[0]) + power(coords[1] - middle[1]))
        circumference = 2*pi*radius
        print(round(circumference, 2))
    except EOFError:
        exit(0)
