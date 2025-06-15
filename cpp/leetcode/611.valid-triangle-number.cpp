/*
 * @lc app=leetcode id=611 lang=cpp
 *
 * [611] Valid Triangle Number
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
      int n = nums.size(), count = 0;
      sort(nums.begin(), nums.end());
      function<int(int)> countSides = [&](int l) {
        int s = 0, m = l - 1, count = 0;
        while(s < m) {
          if(nums[s] + nums[m] > nums[l]) {
            count += m - s;
            m--;
          } else {
            s++;
          }
        }
        return count;
      };
      for(int i = n - 1; i >= 0; i--) count += countSides(i);
      return count;
    }
};
// @lc code=end

