/*
 * @lc app=leetcode id=1094 lang=cpp
 *
 * [1094] Car Pooling
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(), [](vector<int> a, vector<int> b) {
            return a[1] < b[1];
        });
        auto cmp = [](vector<int> a, vector<int> b) {
            return a[2] > b[2];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq;
        for(auto c: trips) {
            if(pq.empty()) {
                if(c[0] <= capacity) {
                    capacity -= c[0];
                    pq.push(c);
                } 
                else return false;
            } else {
                vector<int> t = pq.top();
                while(!pq.empty() && t[2] <= c[1]) {
                    capacity += t[0];
                    pq.pop();
                    if(!pq.empty()) t = pq.top();
                }
                if(c[0] <= capacity) {
                    capacity -= c[0];
                    pq.push(c);
                } 
                else return false;
            }
        }
        return true;
    }
};
// @lc code=end

