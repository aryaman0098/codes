/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 1) return intervals;
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int n = intervals.size();
        for(int i = 0; i < n - 1; i++) {
            if(intervals[i][1] < intervals[i + 1][0]) ans.push_back(intervals[i]);
            else {
                int j = i;
                int startTime = intervals[j][0];
                int endTime = intervals[j][1];
                i++;
                while(i < n - 1 && endTime >= intervals[i][0]) {
                    endTime = max(endTime, intervals[i][1]);
                    i++;
                }
                if(i == n - 1 && endTime >= intervals[i][0]) endTime = max(endTime, intervals[i][1]);
                else i--;
                ans.push_back({startTime, endTime});
            }
        }
        if(intervals[n - 1][0] > ans[ans.size() - 1][1]) ans.push_back(intervals[n - 1]);
        return ans;
    }
};
// @lc code=end

