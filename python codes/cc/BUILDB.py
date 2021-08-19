t = int(input())
while(t > 0):
    [N, R] = list(map(int, input().split()))
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    max = -1
    tension = 0
    for i in range(0, N):
        tension += B[i]
        if tension > max:
            max = tension
        if i + 1 < N:
            tension = tension - (A[i + 1] - A[i]) * R
            if tension < 0:
                tension = 0
    print(max)
    t-=1