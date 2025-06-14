/*
 * @lc app=leetcode id=1200 lang=cpp
 *
 * [1200] Minimum Absolute Difference
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int minDiff = INT_MAX, n = arr.size();
        vector<vector<int>> ans;
        for(int i = 0; i < n - 1; i++) {
            if(minDiff > (arr[i + 1] - arr[i])) {
                ans = {};
                ans.push_back({arr[i], arr[i + 1]});
                minDiff = arr[i + 1] - arr[i];
            } else if(arr[i + 1] - arr[i] == minDiff) {
                ans.push_back({arr[i], arr[i + 1]});
            }
        }
        return ans;
    }
};
// @lc code=end

