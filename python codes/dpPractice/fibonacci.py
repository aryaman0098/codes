import sys

def fib(n, memo):
    if(n in memo):
        return memo[n]
    if n == 1 or n == 2:
        return 1
    else: 
        memo[n] =  fib(n - 1, memo) + fib(n - 2, memo)
        return memo[n]

print(fib(10000, {})) #for cpp use unordered map
