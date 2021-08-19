t = int(input())
while(t > 0):
    [N, M] = list(map(int, input().split()))
    [X, Y] = list(map(int, input().split()))
    L = []
    for i in range(N):
        L.append(list(input().split()))
    for i in L:
        x = i[0].count("F")
        y = i[0].count("P")
        if(x >= X):
            print("1", end = "")
        elif(x == (X - 1) and y >= Y):
            print("1", end = "")
        else:
            print("0", end = "")
    print()
    t-=1