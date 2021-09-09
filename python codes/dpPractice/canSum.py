#if it possible to get a sum of n from using the elements of array (element can be reused)
import sys

def canSum(targetSum, numbers, memo):
    if(targetSum in memo):
        return memo[targetSum]
    if targetSum == 0:
        return True
    if targetSum < 0:
        return False
    for i in numbers:
        remainder = targetSum - i
        if(canSum(remainder, numbers, memo) == True):
            memo[targetSum] = True
            return True
    memo[targetSum] = False
    return False

print(canSum(7, [2, 3], {}))
print(canSum(8, [2, 3, 5], {}))
print(canSum(7, [2, 4], {}))
print(canSum(300, [7, 14], {}))