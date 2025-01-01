/*
 * @lc app=leetcode id=3386 lang=cpp
 *
 * [3386] Button with Longest Push Time
 */

#include<bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        int maxTime, ans;
        for (int i = 0; i < events.size(); i++) {
            if (i == 0) {
                ans = events[i][0];
                maxTime = events[i][1];
            } else if(maxTime < (events[i][1] - events[i - 1][1])) {
                ans = events[i][0];
                maxTime = events[i][1] - events[i - 1][1];
            } else if(maxTime == (events[i][1] - events[i - 1][1])) {
                ans = min(events[i][0], ans);
            }
        }
        return ans;
    }
};
// @lc code=end

