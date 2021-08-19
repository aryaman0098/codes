t = int(input())
while(t > 0):
    [N, X] = list(map(int, input().split()))
    childs = {}
    allChilds = {}
    for i in range(N -1):
        
        [u, v] = list(map(int, input().split()))
    
        if(u not in childs.keys()):
            childs[u] = []
        childs[u].append(v)
        
        if(u not in allChilds.keys()):
            allChilds[u] = []
        
        for j in childs.keys():
            if u in childs[j]:
                allChilds[j].append(v)
                break
        allChilds[u].append(v)

    numChilds = {}

    for i in allChilds.keys():
        numChilds[i] = len(allChilds[i])
    L ={}
    for i in range(1, N+1):
        L[i] = {}
        if i in childs.keys():
            for j in childs[i]:
                if j in numChilds.keys():
                    L[i][j] = numChilds[j]
                else:
                    L[i][j] = 0
    for i in L.keys():
        L[i] = {k: v for k, v in sorted(L[i].items(), key=lambda item: item[1], reverse = True)}

    values = [X]
    for i in range (1, N):
        values.append(0)
    ans = 0
    for i in range(0, N):
        ans += values[i]
        counter = 1
        for j in L[i + 1].keys():
            values[j - 1] = counter * values[i]
            counter += 1

    print(ans)

    t -= 1
