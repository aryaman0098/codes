#move from (1, 1) to (m, n)

import sys

def gridTraveller(m, n, memo):
    key = (m ,n)
    if key in memo: 
        return memo[(m, n)]
    elif key in memo:
        return memo[(n, m)]
    if(m == 0 or n == 0):
        return 0
    if(m == 1 and n == 1):
        return 1
    else:
        memo[key] = gridTraveller(m - 1, n, memo) + gridTraveller(m, n - 1, memo)
        return memo[key]

print(gridTraveller(18, 18, {}))