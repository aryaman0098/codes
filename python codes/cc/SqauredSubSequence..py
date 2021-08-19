import math
import numpy

def allSubArrays(L,L2=None):
    if L2==None:
        L2 = L[:-1]
    if L==[]:
        if L2==[]:
            return []
        return allSubArrays(L2,L2[:-1])
    return [L]+allSubArrays(L[1:],L2)

T = int(input())
for i in range(0, T):
    N = int(input())
    A = list(map(int,input().split()))
    a = allSubArrays(A, None)
    a.reverse()
    print(a)
    for j in range (0, len(a)):
        a[j] = numpy.prod(a[j])
    print(a)
    counter = 0
    for j in range(0, len(a)):
        if a[j] != 0:
            if a[j] % 4 != 2:
                    counter = counter + 1
    print(counter)
