t = int(input())
while(t > 0):
    [N, M] = list(map(int, input().split()))
    (x, y) = list(map(int, input().split()))
    (a, b) = list(map(int, input().split()))

    if((x, y) == (N, M) or (x + 1, y) == (N, M) or (x, y + 1) == (N, M)):
        print("YES")
    elif(max(N-a, M-b) < (N-x + M-y)):
        print("NO")
    else:
        print("YES")    
    t-=1


