/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int maxSize = 0;
        string ans;
        for(int i = 0; i < n; i++) {
            int l = i;
            int r = i;
            string temp = "";
            while(r + 1 < n && s[r] == s[r + 1]) {
                r++;
            } 

            while(l >= 0 && r < n) {
                if(s[l] != s[r]) {
                    break;
                }
                l--;
                r++;
            }
            if(l + 1 >= 0) {
                temp = s.substr(l + 1, r - l - 1);
            }
            if(temp.length() > maxSize) {
                ans = temp;
                maxSize = temp.length();
            }
        }
        return ans;
    }
};
// @lc code=end

