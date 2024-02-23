def partition(arr, low, high):
    i = (low - 1)  # index of smaller element
    pivot = arr[high]  # pivot

    for j in range (low, high):

        # If current element is smaller than or
        # equal to pivot
        if arr[j] <= pivot:
            # increment index of smaller element
            i += 1
            arr[i], arr[j] = arr[j], arr[i]

    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1


def quickSort(arr, low, high):
    if len(arr) == 1:
        return arr
    if low < high:
        # pi is partitioning index, arr[p] is now
        # at right place
        pi = partition(arr, low, high)

        # Separately sort elements before
        # partition and after partition
        quickSort(arr, low, pi - 1)
        quickSort(arr, pi + 1, high)


def fits(box1, box2):
    for i in range(1, len(box1)):
        if box1[i] > box2[i]:
            return 0
    return 1


def sequence(box, boxes, stacks, length):
    for i in range(len(boxes)):
        if fits(box, boxes[i]):
            length += 1
            return [box[0]] + sequence(boxes[i], boxes[:i] + boxes[i+1:], stacks, length)
    return []


while True:
    try:
        params = list(map(int, input().split()))
        box_count = params[0]
        dimension = params[1]
        boxes = []
        for i in range(box_count):
            # first integer is the position in the array of boxes
            box = [i] + list(map(int, input().split()))
            quickSort(box, 1, dimension-1)
            print(box)
            boxes.append(box)

        stacks = []
        for i in range(box_count):
            stacks.append([])

        for i in range(box_count):
            stacks[i] = sequence(boxes[i], boxes[:i] + boxes[i+1:], stacks, 0)


    except EOFError:
        exit(0)
