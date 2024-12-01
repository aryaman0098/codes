/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 */
#include<bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
      if(s.length () == 0) return 0;
      int open = 0;
      int close = 0;
      int ans = INT_MIN;
      for(int i = 0; i < s.length(); i++) {
        if(s[i] == '(') open++;
        else close++;
        if(open == close) {
          ans = max(ans, open * 2);
        } else if(close > open) {
          open = 0;
          close = 0;
        }
      }
      open = 0;
      close = 0;
      for(int i = s.length() - 1; i >= 0; i--) {
        if(s[i] == ')') close++;
        else open++;
        if(open == close) {
          ans = max(ans, close * 2);
        } else if(open > close) {
          open = 0;
          close = 0;
        }
      }
      return (ans == INT_MIN) ? 0 : ans; 
    }
};
// @lc code=end

