/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int currLength = 0, maxLength = 0, maxFreq = 0, l = 0, r = 0;
        unordered_map<char, int> u;
        while(r < s.length()) {
            u[s[r]]++;
            if(maxFreq < u[s[r]]) maxFreq = u[s[r]];
            currLength = r - l + 1;
            if(currLength - maxFreq <= k) {
                maxLength = max(maxLength, currLength);
            } else {
                while(currLength - maxFreq > k) {
                    u[s[l]]--;
                    l++;
                    currLength = r - l + 1;
                    maxFreq = 0;
                    for(auto c: u) if(maxFreq < c.second) maxFreq = c.second;
                }
            }
            r++;
        }
        return maxLength;
    }
};
// @lc code=end

