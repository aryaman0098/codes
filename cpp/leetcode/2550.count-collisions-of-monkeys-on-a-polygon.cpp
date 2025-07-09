/*
 * @lc app=leetcode id=2550 lang=cpp
 *
 * [2550] Count Collisions of Monkeys on a Polygon
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int monkeyMove(int n) {
        long long res = 1;
        long long base = 2;
        while (n > 0) {
            if (n % 2 == 1) {
                res = (res * base) % 1000000007;
            }
            base = (base * base) % 1000000007;
            n /= 2;
        }
        return (res - 2 + 1000000007) % 1000000007;
    }
};
// @lc code=end

