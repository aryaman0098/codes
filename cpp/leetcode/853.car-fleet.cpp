/*
 * @lc app=leetcode id=853 lang=cpp
 *
 * [853] Car Fleet
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> ps;
        int n = position.size();
        for(int i = 0; i < n; i++) {
            ps.push_back({position[i], (target - position[i]) / speed[i]});
        }
        sort(ps.begin(), ps.end(), [](pair<int, int> a, pair<int, int> b) {
            return a.first < b.first;
        });
        int ans = 0;
        int t = n - 1;
        while(t > 0) {
            if(ps[t].second < ps[t - 1].second) ans++;
            else ps[t - 1] = ps[t];
            t--;
        }
        return ans;
    }
};
// @lc code=end

