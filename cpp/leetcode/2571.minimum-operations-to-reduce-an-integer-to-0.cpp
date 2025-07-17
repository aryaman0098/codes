/*
 * @lc app=leetcode id=2571 lang=cpp
 *
 * [2571] Minimum Operations to Reduce an Integer to 0
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minOperations(int n) {
        if(n == 0) return 0;
        if (n == 1 || n == 2)
            return 1;
        int count = 1;
        int pow2 = 2;
        while (pow2 <= n) {
            count++;
            pow2 *= 2;
        }
        int minDiff = min(n - pow(2, count - 1), pow(2,  count) - n);
        return 1 + minOperations(minDiff);
    }
};
// @lc code=end

