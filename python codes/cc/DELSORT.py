def orderedpairs(L):
    for i in range(1, len(L) + 1):
        for j in range(i, len(L) + 1):
            lrs.append([i, j])

t = int(input())
while(t > 0):
    N = int(input())
    A = list(map(int, input().split()))
    lr= []
    lrs = []
    for i in range(1, N + 1):
        lr.append(i)
    orderedpairs(lr)
    count = 0
    for i in range (len(lrs)):
        A_ = []
        L = A[lrs[i][0] - 1 : lrs[i][1]]
        for j in A:
            if j not in L :
                A_.append(j)
        if len(A_) == 0 or len(A_) == 1:
            count+=1
        else:
            flag = 0
            for l in range (len(A_) - 1):
                if A_[l] > A_[l + 1]:
                    flag = 1
                    break
            if flag == 0:
                count+=1
    print(count)
    t-=1


