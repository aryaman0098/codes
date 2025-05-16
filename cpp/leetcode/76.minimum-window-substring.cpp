/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if(s.length() < t.length()) return "";
        unordered_map<char, int> u, u2;
        for(auto c: t) u[c]++;
        int l = 0, r = 0, formed = 0, minSize = INT_MAX, start = 0;
        while(r < s.length()) {
            u2[s[r]]++;
            if(u.find(s[r]) != u.end() && u[s[r]] == u2[s[r]]) {
                formed++;
            }
            while(l <= r && formed == u.size()) {
                if(minSize > r - l + 1) {
                    minSize = r - l + 1;
                    start = l;
                }
                u2[s[l]]--;
                if(u.find(s[l]) != u.end() && u2[s[l]] < u[s[l]]) formed--;
                l++;
            }
            r++;
        }
        return (minSize == INT_MAX) ? "" : s.substr(start, minSize); 
    }
};
// @lc code=end

