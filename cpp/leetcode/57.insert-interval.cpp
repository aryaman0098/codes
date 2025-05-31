/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.size() == 0) return {newInterval};
        if(newInterval[1] < intervals[0][0]) {
            intervals.insert(intervals.begin(), newInterval);
            return intervals;
        }
        int n = intervals.size();
        if(newInterval[0] > intervals[n - 1][1]) {
            intervals.push_back(newInterval);
            return intervals;
        }
        vector<vector<int>> ans;
        bool intervalInserted = false;
        for(int i = 0; i < n; i++) {
            if(!intervalInserted) {
                if(!(newInterval[0] < intervals[i][0] || (intervals[i][0] <= newInterval[0] && newInterval[0] <= intervals[i][1]))) ans.push_back(intervals[i]);
                else {
                    int startTime = min(intervals[i][0], newInterval[0]);
                    while(i < n && !(newInterval[1] < intervals[i][0] || (intervals[i][0] <= newInterval[1] && newInterval[1] <= intervals[i][1]))) i++;
                    int endTime;
                    if(i == n) {
                        endTime = newInterval[1];
                    }
                    else if(newInterval[1] < intervals[i][0]) {
                        endTime = newInterval[1];
                        i--;
                    } else if(intervals[i][0] <= newInterval[1] && newInterval[1] <= intervals[i][1]) {
                        endTime = intervals[i][1];
                    } 
                    ans.push_back({startTime, endTime});
                    intervalInserted = true;
                }
            } else {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};
// @lc code=end

