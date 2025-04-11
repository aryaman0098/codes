/*
 * @lc app=leetcode id=1353 lang=cpp
 *
 * [1353] Maximum Number of Events That Can Be Attended
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int maxEvents(vector<vector<int>>& events) {
            sort(events.begin(), events.end());
            priority_queue<int, vector<int>, greater<int>> pq;
            int day = 1, i = 0, res = 0;
            int n = events.size();
            int lastDay = 0;
            for (auto& e : events) {
                lastDay = max(lastDay, e[1]);
            }
            while (day <= lastDay) {
                while (i < n && events[i][0] == day) {
                    pq.push(events[i][1]);
                    i++;
                }
                while (!pq.empty() && pq.top() < day) {
                    pq.pop();
                }
                if (!pq.empty()) {
                    pq.pop();
                    res++;
                }
                day++;
            }
            return res;
        }
    };
// @lc code=end

