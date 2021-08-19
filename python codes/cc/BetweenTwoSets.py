import math
import os
import random
import re
import sys

#
# Complete the 'getTotalX' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER_ARRAY a
#  2. INTEGER_ARRAY b
#

def getTotalX(a, b):
    
    m = max(a)
    M = min(b)
    l = []
    flag = False
    for i in range (m, M):
        for j in range(0, len(a)):
            if (i % a[j] == 0):
                flag = True
            else :   
                flag = False
                break
        if flag:
            l.append(i)
    if len(l) == 0:
        return 0
    
    else:     
        index = 0
        flag = False        
        for i in range (0, len(b)):
            for j in range (0, len(l)):
                if(b[i] % l[j] == 0):
                    flag = True
                else:    
                    flag = False
                    index = j
                    break
            if (not flag):
                y = l[index]
                l.remove(y)
        
        return len(l)


print(getTotalX([2, 4], [16, 32, 96]))