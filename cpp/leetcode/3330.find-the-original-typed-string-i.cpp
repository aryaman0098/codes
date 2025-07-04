/*
 * @lc app=leetcode id=3330 lang=cpp
 *
 * [3330] Find the Original Typed String I
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int possibleStringCount(string word) {
        int ans = 1, n = word.size();
        for (int i = 0; i < n; i++) {
            int count = 1;
            while (i < n - 1 && word[i] == word[i + 1]) {
                count++;
                i++;
            }
            ans += (count > 1) ? count - 1 : 0;
        }
        return ans;
    }
};
// @lc code=end

