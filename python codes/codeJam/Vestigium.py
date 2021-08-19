T = int(input())
t = 1
while(t <= T):
    N = int(input())
    L = []
    k = 0
    r = 0
    c = 0
    for i in range (0, N):
        L.append(input().split())
        k = k + int(L[i][i])
        if len(L[i]) != len(set(L[i])):
            r = r + 1
    for i in range (0, N):
        L_ = []
        for j in range (0, N):
           L_.append(L[j][i])
        if len(L_) != len(set(L_)):
            c = c + 1
    print(f"Case #{t}: {k} {r} {c}")
    
    t = t + 1