/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, int> u;
        while (n != 1) {
            if (u.find(n) != u.end())
                return false;
            u[n] = 1;
            int sum = 0, q = 10;
            while (n > 0) {
                sum += pow(n % q, 2);
                n /= 10;
            }
            n = sum;
        }
        return true;
    }
};
// @lc code=end

