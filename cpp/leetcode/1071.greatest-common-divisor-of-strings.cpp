/*
 * @lc app=leetcode id=1071 lang=cpp
 *
 * [1071] Greatest Common Divisor of Strings
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
      if(str1 + str2 != str2 + str1) return "";
      int len1, len2;
      if(str1.length() >= str2.length()) {
        len1 = str1.length();
        len2 = str2.length();
      } else {
        len1 = str2.length();
        len2 = str1.length();
      } 
      while(len2 != 0) {
        int temp = len2;
        len2 = len1 % len2;
        len1 = temp;
      }
      return str1.substr(0, len1);     
    }
};
// @lc code=end

