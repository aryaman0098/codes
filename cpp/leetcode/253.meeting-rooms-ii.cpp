/*
 * @lc app=leetcode id=253 lang=cpp
 *
 * [253] Meeting Rooms II
 */

#include<bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) { 
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            if(a[0] == b[0]){
                return a[1] > b[1];
            } else {
                return a[0] < b[0];
            }
        });
        int numberOfRooms = 1;
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(intervals[0][1]);
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i][0] <  pq.top()) {
                numberOfRooms += 1;
            } 
            else {
                pq.pop();
            }
            pq.push(intervals[i][1]);
        }
        return numberOfRooms;
    }
};
// @lc code=end

