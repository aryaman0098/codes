/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */
#include<bits/stdc++.h>

using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      vector<vector<int>> ans;
      sort(nums.begin(), nums.end());
      for(int i = 0; i < nums.size(); i++) {
        int target = -nums[i];
        int l = i + 1, r = nums.size() - 1;
        while(l < r) {
          if((nums[l] + nums[r]) < target) {
            l++;
          } else if((nums[l] + nums[r]) > target) {
            r--;
          } else {
            ans.push_back({nums[i], nums[l], nums[r]});
            while(l < nums.size() - 1 && l < r && nums[l] == nums[l + 1])  {
              l++;
            } 
            while(r > 0 && l < r && nums[r] == nums[r - 1]) r--;
            l++;
            r--;
          }
        }
        while(i < nums.size() - 1 && nums[i] == nums[i + 1]) i++;
      }
      return ans;
    }
};
// @lc code=end

