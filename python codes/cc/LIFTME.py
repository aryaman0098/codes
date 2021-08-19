T = int(input())
for i in range (0, T):
    N , Q = map(int, input().split())
    initial = 0
    sum = 0
    for j in range(0, Q):
        fi, di = map(int, input().split()) 
        if fi > di:
            sum = sum + abs(abs(fi - initial) + abs(di - fi))
        else:
            sum = sum + abs(abs(fi - initial) + abs(di - fi))
        initial = di
    print(sum)



