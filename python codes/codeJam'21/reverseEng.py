from itertools import permutations

def revSortCost(L):
    sum = 0
    for i in range (len(L) - 1):
        j = L.index(min(L[i : ]))
        L[i : j + 1] = reversed(L[i : j + 1])
        sum += (j - i + 1)
    return sum


T = int(input())
t = 1
while(t <= T):
    N, C = input().split()
    N = int(N)
    C = int(C)
    L_ = []
    for i in range (1, N + 1):
        L_.append(i)
    L = permutations(L_)
    flag = 0
    for i in L:
        C_ = revSortCost(list(i))
        if C_ == C:
            flag = 1
            print(f"Case #{t}:", end = "")
            for j in i:
                print(" " + str(j), end = "")
            print()
            break
    if flag == 0:
        print(f"Case #{t}: IMPOSSIBLE") 
    t = t + 1
