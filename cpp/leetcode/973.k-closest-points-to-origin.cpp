/*
 * @lc app=leetcode id=973 lang=cpp
 *
 * [973] K Closest Points to Origin
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        auto cmp = [](pair<int, int> a, pair<int, int> b) {
            return a.first > b.first;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq;
        for(int i = 0; i < n; i++) {
            pq.push({pow(points[i][0],2) + pow(points[i][1], 2), i});
        }
        vector<vector<int>> ans;
        int count = 0;
        while(count < k) {
            ans.push_back(points[pq.top().second]);
            pq.pop();
            count++;
        }
        return ans;
    }
};
// @lc code=end

