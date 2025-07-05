/*
 * @lc app=leetcode id=554 lang=cpp
 *
 * [554] Brick Wall
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        vector<vector<long long>> v;
        unordered_map<long long, int> u;
        int r = wall.size(), maxCount = 0;
        long long end = 0;
        for(int i = 0; i < wall[0].size(); i++) {
            end += wall[0][i];
        }
        for (int i = 0; i < r; i++) {
            long long sum = 0;
            int c = wall[i].size();
            for (int j = 0; j < c; j++) {
                sum += wall[i][j];
                u[sum]++;
                if(sum != end) maxCount = max(maxCount, u[sum]);
            }
        }
        return r - maxCount;
    }
};
// @lc code=end

