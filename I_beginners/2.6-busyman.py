cases = int(input())

for i in range(cases):

    activities = int(input())
    array = []

    for j in range(activities):
        activity = list(map(int, input().split()))
        array.append(activity)
