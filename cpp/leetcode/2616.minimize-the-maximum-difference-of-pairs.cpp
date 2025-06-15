/*
 * @lc app=leetcode id=2616 lang=cpp
 *
 * [2616] Minimize the Maximum Difference of Pairs
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
      int n = nums.size();
      function<int(int)> numPairs = [&](int diff) {
        int numsOfPairs = 0;
        for(int i = 0; i < n - 1; i++) {
          if(nums[i + 1] - nums[i] <= diff) {
            numsOfPairs++;
            i++;
          }
        }
        return numsOfPairs;
      };
      sort(nums.begin(), nums.end());
      int l = 0, r = nums[n - 1] - nums[0];
      while(l < r) {
        int mid = (r + l) / 2;
        if(numPairs(mid) >= p) r = mid;
        else l = mid + 1;
      }
      return l;
    }
};
// @lc code=end

