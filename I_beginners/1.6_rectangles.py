import math
squares = int(input())
root = int(math.sqrt(squares))
rectangles = 0
for i in range(1, root + 1):
    rectangles += squares // i - i + 1
print(rectangles)
