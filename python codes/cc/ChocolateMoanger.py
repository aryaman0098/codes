t = int(input())
while(t > 0):
    [n, x] = list(map(int, input().split()))
    L = list(map(int, input().split()))
    s = set(L)
    if(len(s) <= (len(L) - x)):
        print(len(s))
    else:
        print(len(L) - x)
    t-=1