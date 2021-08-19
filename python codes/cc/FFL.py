T = int(input())
for i in range(0, T):
    N, S = map(int, input().split())
    P = list(map(int, input().split()))
    DF = list(map(int, input().split()))
    S = 100 - S
    minD = 200
    minG =200
    for j in range (0,N):
        if DF[j] == 0:
            if P[j] < minD:
                minD = P[j]
        if DF[j] == 1:
            if P[j] < minG:
                minG = P[j]
    if S >= (minG + minD):
        print("yes")
    else:
        print("no")
