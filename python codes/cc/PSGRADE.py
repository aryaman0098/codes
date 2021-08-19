t = int(input())
while(t > 0):
    l = list(map(int, input().split()))
    if l[0] <= l[4] and l[1] <= l[5] and l[2] <= l[6] and l[3] <= (l[4] + l[5] + l[6]):
        print("YES")
    else:
        print("NO")
    t-=1
