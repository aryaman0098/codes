/*
 * @lc app=leetcode id=2406 lang=cpp
 *
 * [2406] Divide Intervals Into Minimum Number of Groups
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        int groups = 0;
        pq.push(intervals[0][1]);
        for(int i = 0; i < intervals.size(); i++) {
            if(intervals[i][0] < pq.top()) groups++;
            else pq.pop();
            pq.push(intervals[i][1]);
        }
        return groups;
    }
};
// @lc code=end

