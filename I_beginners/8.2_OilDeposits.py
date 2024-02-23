def deposit(height, width, i, j):
    if j+1 < width and field[i][j+1] == "@" and visited[i][j+1] == 0:
        visited[i][j+1] = 1
        deposit(height, width, i, j+1)

    if i+1 < height and j+1 < width and field[i+1][j+1] == "@" and visited[i+1][j+1] == 0:
        visited[i+1][j+1] = 1
        deposit(height, width, i+1, j+1)

    if i+1 < height and field[i+1][j] == "@" and visited[i+1][j] == 0:
        visited[i+1][j] = 1
        deposit(height, width, i+1, j)

    if i+1 < height and j-1 >= 0 and field[i+1][j-1] == "@" and visited[i+1][j-1] == 0:
        visited[i+1][j-1] = 1
        deposit(height, width, i+1, j-1)

    if j-1 >= 0 and field[i][j-1] == "@" and visited[i][j-1] == 0:
        visited[i][j-1] = 1
        deposit(height, width, i, j-1)

    if i-1 >= 0 and j-1 >= 0 and field[i-1][j-1] == "@" and visited[i-1][j-1] == 0:
        visited[i-1][j-1] = 1
        deposit(height, width, i-1, j-1)

    if i-1 >= 0 and field[i-1][j] == "@" and visited[i-1][j] == 0:
        visited[i-1][j] = 1
        deposit(height, width, i-1, j)
    if i-1 >= 0 and j+1 < width and field[i-1][j+1] == "@" and visited[i-1][j+1] == 0:
        visited[i-1][j+1] = 1
        deposit(height, width, i-1, j+1)


while True:
    field = []
    params = list(map(int, input().split()))
    if 0 in params:
        break

    for i in range(params[0]):
        field.append(input())

    # for i in range(params[0]):
    #     for j in range(len(field[i])):
    #         print(field[i][j], end=" ")
    #     print("")
    # print("")

    count = 0
    visited = []
    for i in range(params[0]):
        tmp = []
        for j in range(params[1]):
            tmp.append(0)
        visited.append(tmp)

    for i in range(params[0]):
        for j in range(params[1]):

            # for i1 in range (params[0]):
            #     for j1 in range (params[1]):
            #         print(visited[i1][j1], end=" ")
            #     print("")
            # print("")

            if visited[i][j] == 0:
                visited[i][j] = 1
                if field[i][j] == "@":
                    count += 1
                    deposit(params[0], params[1], i, j)
    print(count)



