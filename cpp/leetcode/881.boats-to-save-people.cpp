/*
 * @lc app=leetcode id=881 lang=cpp
 *
 * [881] Boats to Save People
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
      sort(people.begin(), people.end());
      int ans = 0, l = 0, r = people.size() - 1;
      while(l <= r) {
        ans++;
        if(people[l] + people[r] <= limit) l++;
        r--;
      }
      return ans;
    }
};
// @lc code=end

