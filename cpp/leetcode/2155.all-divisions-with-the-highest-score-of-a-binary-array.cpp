/*
 * @lc app=leetcode id=2155 lang=cpp
 *
 * [2155] All Divisions With the Highest Score of a Binary Array
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n = nums.size();
        vector<int> ps(n);
        ps[0] = nums[0];
        for(int i = 1; i < n; i++) ps[i] = ps[i - 1] + nums[i];
        vector<int> indicesScore(n + 1);
        int maxScore = INT_MIN;
        for(int i = 0; i <= n; i++) {
            int sLeft, sRight;
            if(i == 0) {
                sLeft = 0;
                sRight = ps[n - 1];
            } else if(i == n) {
                sLeft = n - ps[n - 1];
                sRight = 0;
            } else {
                sLeft = i - ps[i - 1];
                sRight = ps[n - 1] - ps[i - 1];
            }

            indicesScore[i] = sLeft + sRight;
            maxScore = max(maxScore, indicesScore[i]);
        }
        vector<int> ans;
        for(int i = 0; i <= n; i++) if (indicesScore[i] == maxScore) ans.push_back(i);
        return ans;
    }
};
// @lc code=end

