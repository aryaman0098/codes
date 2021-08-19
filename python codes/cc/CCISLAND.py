t = int(input())
while(t > 0):
    [x,y,xr,yr,D] = list(map(int, input().split()))
    food = x / xr
    water = y / yr
    if(D > min(food, water)):
        print("NO")
    else:
        print("YES")
    t-=1