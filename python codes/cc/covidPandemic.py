try:
    T = int(input())
    for i in range(0, T):
        N = int(input())
        A = list(map(int,input().split()))
        flag = 0
        if N == 1 and A[0] == 1:
            flag = 1
        elif set(A) == {0}:
            flag = 1
        elif A.count(1) == 1:
            flag = 1
        else:
            for i in range (0, len(A)):
                if A[i] == 1:
                    index = i
            for i in range (0, index):
                flag = 1
                if A[i] == 1:
                    c = 0
                    for j in range(i + 1, index):
                        if A[j] == 0:
                            c = c + 1
                        elif A[j] == 1:
                            break
                    if c < 5:
                        flag = 0
                        break
                    elif c >= 5:    
                        flag = 1
                if flag == 0:
                    break
        if flag == 1:
            print("YES")
        else:
            print("NO")       

except:
    pass