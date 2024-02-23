cases = int(input())

for i in range(1, cases+1):
    lengths = list(map(int, input().split()))
    if 0 in lengths:
        print("Case {}: Invalid".format(i))
    elif (lengths[0] >= lengths[1] + lengths[2]
        or lengths[1] >= lengths[2] + lengths[0]
        or lengths[2] >= lengths[0] + lengths[1]):
        print("Case {}: Invalid".format(i))
    elif lengths[0] == lengths[1] == lengths[2]:
        print("Case {}: Equilateral".format(i))
    elif (lengths[0] == lengths[1]
          or lengths[1] == lengths[2]
          or lengths[2] == lengths[0]):
        print("Case {}: Isosceles".format(i))
    else:
        print("Case {}: Scalene".format(i))

