T = int(input())
for i in range (0, T):
    N = int(input())
    S = input()
    f = []
    f.append(S.count("R"))
    f.append(S.count("B"))
    f.append(S.count("G"))
    m = max(f)
    if m == N:
        print(0)
    else :
        print(N - m)    


