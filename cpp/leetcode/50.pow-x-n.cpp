/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
      function<double(double, long long)> binaryExp = [](double x, long long n) {
        if(n == 0) return 1.0;
        if(n == 1) return x;
        if(n < 0) {
          x = 1 / x;
          n *= -1;
        }
        double ans = 1;
        while(n > 0) {
          if(n % 2 == 1) {
            ans *= x;
            n -= 1;
          } else {
            x = x * x;
            n /= 2;
          }
        }   
        return ans;
      };
      return binaryExp(x, (long long) n);
    }
};
// @lc code=end

