import math
T = int(input())
for i in range (0, T):
    N, K = map(int,input().split())
    W = list(map(int,input().split()))
    w1 = W.copy()
    minW1 = []
    minW2 = []
    for j in range(0, K):
        Min = min(w1)
        minW1.append(Min)
        w1.remove(Min)
    sum1 = sum(w1) - sum(minW1)
    w1 = W.copy()
    for j in range(0, N-K):
        Min = min(w1)
        minW2.append(Min)
        w1.remove(Min)
    sum2 = sum(w1) - sum(minW2)
    if sum1>sum2:
        print(sum1)
    elif sum2>sum1:
        print(sum2)
    else:
        print(sum1)

