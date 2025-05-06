/*
 * @lc app=leetcode id=452 lang=cpp
 *
 * [452] Minimum Number of Arrows to Burst Balloons
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](vector<int> a, vector<int>b) {
            return a[0] < b[0];
        });
        int count = 1, n = points.size(), minEndingBalloon = points[0][1];
        for(int i = 1; i < n; i++) {
            if(minEndingBalloon < points[i][0]) {
                count++;
                minEndingBalloon = points[i][1];
            } else {
                minEndingBalloon = min(minEndingBalloon, points[i][1]);
            }
        }
        return count;
    }
};
// @lc code=end

