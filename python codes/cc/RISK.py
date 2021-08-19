def markCurrentIsland(L, i, j, N, M):
    if(i < 0 or i >= N or j < 0 or j >= M or L[i][j] != "1"):
        return
    
    L[i][j] = "2"
    global landSize
    landSize += 1

    markCurrentIsland(L, i + 1, j, N, M)
    markCurrentIsland(L, i, j + 1, N, M)
    markCurrentIsland(L, i - 1, j, N, M)
    markCurrentIsland(L, i, j - 1, N, M)
    


t = int(input())
while(t > 0):
    [N, M] = list(map(int, input().split()))
    L = []
    count = 0
    for i in range(N):
        s = input()
        L_ = []
        for j in s:
            L_.append(j)
        L.append(L_)

    landCount =  []
    global landSize
    landSize = 0
    for i in range(N):
        for j in range(M):
            if L[i][j] == "1":
                markCurrentIsland(L, i, j, N, M)
                landCount.append(landSize)
                landSize = 0
    landCount.sort(reverse = True)
    ans = 0
    for i in range(len(landCount)):
        if (i % 2 != 0):
            ans += landCount[i]
    print(ans)
    t-=1