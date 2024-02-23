import math
pi = 3.141592653589793


def power(x):
    return x*x


while True:
    try:
        lengths = list(map(float, input().split()))

        circumference2 = lengths[0] + lengths[1] + lengths[2]
        s = circumference2/2
        content2 = math.sqrt(s*(s-lengths[0])*(s-lengths[1])*(s-lengths[2]))

        radius1 = lengths[0]*lengths[1]*lengths[2]/(4*content2)
        content1 = pi*radius1*radius1

        radius3 = 2*content2/circumference2
        content3 = pi*radius3*radius3
        area1 = round(content1-content2, 4)
        area2 = round(content2-content3, 4)
        area3 = round(content3, 4)
        print("{a1:.4f} {a2:.4f} {a3:.4f}".format(a1=area1, a2=area2, a3=area3))
    except EOFError:
        exit(0)
