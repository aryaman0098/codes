/*
 * @lc app=leetcode id=621 lang=cpp
 *
 * [621] Task Scheduler
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> u;
        for(char c: tasks) u[c]++;
        auto cmp = [](pair<char, int> a, pair<char, int> b) {
            if(a.second == b.second) return a.first > b.first;
            else return a.second < b.second;
        };
        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(cmp)> pq;
        for(auto c: u) pq.push(c);
        queue<pair<pair<char, int>, int>> q;
        int time = 0;
        while(!pq.empty() || !q.empty()) {
            time++;
            if(!q.empty()) {
                pair<pair<char, int>, int> p = q.front();
                if(p.second <= time) {
                    pq.push(p.first);
                    q.pop();
                }
            }
            if(!pq.empty()) {
                pair<char, int> p = pq.top();
                pq.pop();
                p.second = p.second - 1;
                if(p.second > 0) {
                    q.push({p, time + n + 1});
                }
            } 
        }
        return time;
    }
};
// @lc code=end

