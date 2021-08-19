T = int(input())
t = 1
while(t <= T):
    N = int(input())
    L = list(map(int, input().strip().split()))
    sum = 0
    for i in range (len(L) - 1):
        j = L.index(min(L[i : ]))
        L[i : j + 1] = reversed(L[i : j + 1])
        sum += (j - i + 1)
    print(f"Case #{t}: {sum}")
    t += 1