/*
 * @lc app=leetcode id=409 lang=cpp
 *
 * [409] Longest Palindrome
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<int, int> u;
        for(char c: s) {
            if(u.find(c) == u.end()) u[c] = 0;
            u[c] += 1;
        }
        int ans = 0;
        bool oddFrequency = false;
        for(auto c: u) {
            if(c.second % 2 == 0) {
                ans += c.second;
            } else {
                ans += c.second - 1;
                oddFrequency = true;
            }
        }
        return (oddFrequency) ? ans + 1: ans;
    }
};
// @lc code=end

