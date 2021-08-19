def score(L):
    anD = L[0]
    for i in range(len(L)):
        anD &= L[i]
    return anD

def bitwiseOR(arr, start, end):  
    if end == len(arr):
        return
    elif start > end:
        return bitwiseOR(arr, 0, end + 1)
    else:
        global oR
        oR|=score(arr[start:end + 1])
        return bitwiseOR(arr, start + 1, end)

t = int(input())
global oR
while(t > 0):
    [N, Q] = list(map(int, input().split()))
    A = list(map(int, input().split()))
    query = []
    for i in range (Q):
        [x, v] = list(map(int, input().split()))
        query.append([x, v])
    oR = 0
    bitwiseOR(A, 0, 0)
    print(oR)
    for [x, v] in query:
        oR = 0
        A[x - 1] = v
        bitwiseOR(A, 0, 0)
        print(oR)
    t-=1
    


