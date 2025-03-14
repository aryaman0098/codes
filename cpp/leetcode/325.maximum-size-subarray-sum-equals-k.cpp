/*
 * @lc app=leetcode id=325 lang=cpp
 *
 * [325] Maximum Size Subarray Sum Equals k
 */

#include<bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
    public:
        int maxSubArrayLen(vector<int>& nums, int k) {
            int n = nums.size();
            vector<long> prefixSum(n, 0);
            unordered_map<int, int> u;
            prefixSum[0] = nums[0];
            for(int i = 1; i < n; i++) {
                prefixSum[i] = prefixSum[i - 1] + nums[i];
            }
            int ans = 0;
            for(int i = 0; i < n; i++) {
                if(prefixSum[i] == k) {
                    ans = max(ans, i + 1);
                } 
                if(u.find(prefixSum[i] - k) != u.end()) {
                    int l = u[prefixSum[i] - k];
                    ans = max(ans, i - l); 
                }
                if(u.find(prefixSum[i]) == u.end()) {
                    u[prefixSum[i]] = i;
                }
            }
            return ans;
        }
    };
// @lc code=end

