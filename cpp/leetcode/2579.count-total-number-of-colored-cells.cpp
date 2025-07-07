/*
 * @lc app=leetcode id=2579 lang=cpp
 *
 * [2579] Count Total Number of Colored Cells
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long coloredCells(int n) {
        return 1 + 2LL * (n - 1) * n;
    }
};
// @lc code=end

