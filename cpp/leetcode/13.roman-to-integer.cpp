/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int romanToInt(string s) {
      unordered_map<char, int> u;
      u['I'] = 1;
      u['V'] = 5;
      u['X'] = 10;
      u['L'] = 50;
      u['C'] = 100;
      u['D'] = 500;
      u['M'] = 1000;
      int ans = 0;
      for(int i = 0; i < s.length(); i++) {
        if(i != s.length() - 1 && (u[s[i]] < u[s[i + 1]])) {
          ans += u[s[i + 1]] - u[s[i]];
          i++;
        } else {
          ans += u[s[i]];
        }
      }
      return ans;
    }
};
// @lc code=end

