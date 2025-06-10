/*
 * @lc app=leetcode id=410 lang=cpp
 *
 * [410] Split Array Largest Sum
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
      function<int(int)> splitArray = [&](int maxNum) {
        int numSplits = 1, currSum = 0;
        for(int i = 0; i < nums.size(); i++) {
          currSum += nums[i];
          if(currSum > maxNum) {
            numSplits++;
            currSum = nums[i];
          }
        }
        return numSplits;
      };
      int sum = 0, maxVal = INT_MIN;
      for(auto c: nums) {
        sum += c;
        maxVal = max(maxVal, c);
      }
      int l = maxVal, r = sum;
      while(l <= r) {
        int mid = (r + l) / 2;
        if(splitArray(mid) > k) l = mid + 1;
        else r = mid - 1;
      }
      return l;
    }
};
// @lc code=end

