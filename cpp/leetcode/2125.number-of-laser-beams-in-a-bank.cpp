/*
 * @lc app=leetcode id=2125 lang=cpp
 *
 * [2125] Number of Laser Beams in a Bank
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0, prevCount = INT_MIN, r = bank.size(),
            c = bank[0].size();
        for (int i = 0; i < r; i++) {
            int newCount = 0;
            for (int j = 0; j < c; j++)
                if (bank[i][j] == '1')
                    newCount++;
            if (newCount > 0) {
                if (prevCount != INT_MIN) {
                    ans += prevCount * newCount;
                }
                prevCount = newCount;
            }
        }
        return ans;
    }
};
// @lc code=end

