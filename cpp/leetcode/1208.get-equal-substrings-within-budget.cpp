/*
 * @lc app=leetcode id=1208 lang=cpp
 *
 * [1208] Get Equal Substrings Within Budget
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length(), maxLen = 0, currLen = 0, l = 0, r = 0;
        while (r < n) {
            maxCost -= abs(s[r] - t[r]);
            while (maxCost < 0) {
                maxCost += abs(s[l] - t[l]);
                l++;
            }
            currLen = r - l + 1;
            maxLen = max(maxLen, currLen);
            r++;
        }
        return maxLen;
    }
};
// @lc code=end

