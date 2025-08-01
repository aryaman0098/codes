/*
 * @lc app=leetcode id=1423 lang=cpp
 *
 * [1423] Maximum Points You Can Obtain from Cards
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int rightMax = 0, leftMax = 0, n = cardPoints.size();
        for (int i = 0; i < k; i++)
            leftMax += cardPoints[i];
        int ans = leftMax;
        for (int i = 0; i < k; i++) {
            rightMax += cardPoints[n - 1 - i];
            leftMax -= cardPoints[k - 1 - i];
            ans = max(ans, rightMax + leftMax);
        }
        return ans;
    }
};
// @lc code=end

