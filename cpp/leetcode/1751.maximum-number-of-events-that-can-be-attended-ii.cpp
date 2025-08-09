/*
 * @lc app=leetcode id=1751 lang=cpp
 *
 * [1751] Maximum Number of Events That Can Be Attended II
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        int n = events.size();
        vector<int> nextIndex(n, n);

        for (int i = 0; i < n; i++) {
            auto it = lower_bound(
                events.begin() + i + 1, events.end(), events[i][1] + 1,
                [](const vector<int>& v, int val) { return v[0] < val; });
            nextIndex[i] = it - events.begin();
        }
        vector<vector<int>> c(n + 1, vector<int>(k + 1, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < k; j++) {
                int skip = c[i + 1][j];
                int take = events[i][2] + c[nextIndex[i]][j + 1];
                c[i][j] = max(skip, take);
            }
        }

        return c[0][0];
    }
};
// @lc code=end

