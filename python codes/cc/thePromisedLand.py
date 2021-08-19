T = int(input())
for i in range (0, T):
    N, M = input().split()
    N = int(N)
    M = int(M)
    X, Y, S = input().split()
    X = int(X)
    Y = int(Y)
    S = int(S)
    Xi = []
    Yi = []
    if X != 0:
        Xi = list(map(int,input().split()))
    if Y != 0:
        Yi = list(map(int,input().split()))
    Ni = []
    Mi = []
    for i in range (1, N+1):
        if not(i in Xi):
            Ni.append(i)
    for i in range (1, M+1):
        if not(i in Yi):
            Mi.append(i)
    S1 = 0
    S2 = 0
    c1 = 1
    c2 = 1
    for i in range(0, (len(Ni)-1)):
        if (Ni[i] + 1) == Ni[i+1] :
            c1 = c1 + 1
        else:
            S1 = S1 + c1//S
            c1 = 1
    S1 = S1 + c1//S

    for i in range(0, (len(Mi)-1)):
        if (Mi[i] + 1) == Mi[i+1] :
            c2 = c2 + 1
        else:
            S2 = S2 + c2//S
            c2 = 1
    S2 = S2 + c2//S
    print(S1 * S2)