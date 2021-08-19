T = int(input())
for i in range(0,T):
    N = int(input())
    S = input()
    Q = int(input())
    MOD = 10**9 + 7
    for j in range (0,Q):
        a = list(input().split())
        if a[0] == "1":
             S = S[0:int(a[1])-1] + "".join(a[3]*(int(a[2])+1-int(a[1]))) + S[int(a[2]):] 
        elif a[0] == "2":
            for k in range (int(a[1])-1, int(a[2])):
                if S[k] == "A":
                    p = int(a[3])
                    a[3] = str((int(a[3]) - int(a[4]) + MOD) % MOD)
                    a[4] = str((p + int(a[4])) % MOD)
                elif S[k] == "B":
                    p = int(a[3])
                    a[3] = str((int(a[3]) + int(a[4])) % MOD)
                    a[4] = str((int(a[4]) - p + MOD) % MOD)
                print(int(a[3])," ",end="")
                print(int(a[4]))