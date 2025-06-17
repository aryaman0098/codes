/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
      int mid = 0, n = nums.size();
      vector<int> ans;
      for(;mid < n; mid++) {
        if(nums[mid] >= 0) break;
      }
      int l = mid - 1, r = mid;
      while (l >= 0 && r < n) {
        if(abs(nums[l]) < abs(nums[r])) {
          ans.push_back(pow(nums[l], 2));
          l--;
        } else {
          ans.push_back(pow(nums[r], 2));
          r++;
        }
      }
      while(l >= 0) {
        ans.push_back(pow(nums[l], 2));
        l--;
      } 
      while(r < n) {
        ans.push_back(pow(nums[r], 2));
        r++;
      } 
      return ans;
    }
};
// @lc code=end

