class Node:
    def __init__(self, dataval=None):
        self.dataval = dataval
        self.nextval = None


class SLinkedList:
    def __init__(self):
        self.headval = None

    def listprint(self):
        printval = self.headval
        while printval is not None:
            print(printval.dataval, end=" ")
            printval = printval.nextval
        print("")


cases = int(input())

for i in range(cases):
    samples = int(input())
    count = 0
    maxCount = 0

    snowflakes = SLinkedList()
    current = Node()

    for j in range(samples):
        if count == 0:
            snowflakes.headval = Node(int(input()))
            current = snowflakes.headval
        else:
            newSnowflake = Node(int(input()))

            comparing = snowflakes.headval

            k = 0
            while comparing is not None:
                # print(newSnowflake.dataval, "=?", comparing.dataval)
                if newSnowflake.dataval == comparing.dataval:
                    # print("same")

                    if comparing.nextval is not None:
                        snowflakes.headval = comparing.nextval
                    else:
                        snowflakes.headval = newSnowflake

                    if count > maxCount:
                        maxCount = count
                    count -= k + 1
                    break

                comparing = comparing.nextval
                k += 1

            current.nextval = newSnowflake
            current = current.nextval

        count += 1
        # print("snowflakes:", end=" ")
        # snowflakes.listprint()

    if count > maxCount:
        maxCount = count
    print(maxCount)
