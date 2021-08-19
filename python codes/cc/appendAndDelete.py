import math
import os
import random
import re
import sys

# Complete the appendAndDelete function below.
def appendAndDelete(s, t, k):
    sl = len(s)
    tl = len(t)
    if sl <= tl:
        counter = 0
        for i in range (0,sl):
            if s[i] == t[i]:
                counter = counter + 1
            else:
                break
        a = sl - counter
        b = tl - counter
        if (a + b) <= k:
            if ((a != 0) and (b!= 0) and ((k - (a + b)) % 2) == 0):
                return "Yes"
            
            elif a == 0 and b == 0:
                if (sl + tl) <= k:
                    return "Yes"
                else:
                    return "No"
            elif a == 0 and b!=0:
                c = k - b
                if c % 2 == 0:
                    return "Yes"
                else:
                    return "No"
            else:
                return "No"
        else :
            return "No"
    else:
        counter = 0
        for i in range (0,tl):
            if s[i] == t[i]:
                counter = counter + 1
            else:
                break
        a = sl - counter
        b = tl - counter
        if (a + b) <= k:
            return "Yes"
        else:
            return "No"

print(appendAndDelete("abcdef", "fedcba", 15))