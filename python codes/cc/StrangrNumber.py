import math

try:
    T = int(input())
    for j in range (0, T):
        X, K = input().split()
        X = int(X)
        K = int(K)
        c = 0
        for i in range (2, int(math.sqrt(X))+1):
            if X % i == 0:
                c = c + 1
                if X/i != i:
                    c = c + 1
        if c >= K:
            print(1)
        else:
            print(0)
except:
    pass