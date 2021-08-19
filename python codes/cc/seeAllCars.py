T = int(input())
for i in range(0, T):
    N = int(input())
    P = list(map(int,input().split()))
    profit = 0
    P.sort()
    P.reverse()
    for i in range (0, len(P)):
        if (P[i] - i) > 0:
            profit = profit + P[i] - i
        else:
            break
    print(profit % (1000000007))

