/*
 * @lc app=leetcode id=930 lang=cpp
 *
 * [930] Binary Subarrays With Sum
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
      unordered_map<int, int> u;
      int ans = 0, ps = 0;
      for(auto c: nums) {
        ps += c;
        if(ps == goal) ans++;
        if(u.find(ps-goal) != u.end()) ans += u[ps - goal];
        u[ps]++;
      } 
      return ans;
    }
};
// @lc code=end

