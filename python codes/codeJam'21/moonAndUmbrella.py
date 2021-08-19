T = int(input())
t = 1
while(t <= T):
    X, Y, S = input().split()
    X = int(X)
    Y = int(Y)
    sum = 0
    for i in range (len(S)):
        if i == len(S) - 1:
            continue
        elif S[i] == "C" and S[i + 1] == "J":
            sum = sum + X
        elif S[i] == "J" and S[i + 1] == "C":
            sum = sum + Y
        elif S[i] == "?":
            if i == 0:
                continue
            if S[i - 1] == S[i + 1]:
                continue
            elif S[i - 1] == "J" and S[i + 1] == "C":
                sum = sum + Y
            elif S[i - 1] == "C" and S[i + 1] == "J":
                sum = sum + X
            elif S[i - 1] == "C" and S[i + 1] == "?":
                S = S[: i] + "C" + S[i+1 : ]
            elif S[i - 1] == "J" and S[i + 1] == "?":
                S = S[: i] + "J" + S[i+1 : ]
            elif S[i - 1] == "?" and S[i + 1] == "?":
                continue
    print(f"Case #{t}: {sum}")
    t = t + 1
 
