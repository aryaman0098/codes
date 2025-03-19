/*
 * @lc app=leetcode id=1376 lang=cpp
 *
 * [1376] Time Needed to Inform All Employees
 */

#include<bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int, vector<int>> u;
        for(int i = 0; i < manager.size(); i++) {
            if(manager[i] == -1) continue;
            if(u.find(manager[i]) == u.end()) {
                u[manager[i]] = {};
            }
            u[manager[i]].push_back(i);
        }
        queue<int> q;
        vector<int> time(manager.size(), 0);
        q.push(headID);
        int maxTime = 0;
        while(!q.empty()) {
            int employee = q.front();
            q.pop();
            int timeForThisEmployee = time[employee];
            if(u.find(employee) == u.end()) continue;
            for(auto c: u[employee]) {
                time[c] = timeForThisEmployee + informTime[employee];
                maxTime = max(maxTime, time[c]);
                q.push(c);
            }
        }
        return maxTime;
    }
};
// @lc code=end

