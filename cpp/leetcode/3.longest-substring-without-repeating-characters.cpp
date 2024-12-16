/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

#include<bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0) return 0;
		unordered_map<char, int> charCount;
		int l = 0, r = 0, max = INT_MIN;
		while(l < s.length() && r < s.length()) {
			if(
				charCount.find(s[r]) == charCount.end() || 
				charCount[s[r]] == 0
			) {
				charCount[s[r]] = 1;
				r++;
				if(r - l > max) max = r - l;
			} else {
				while(s[l] != s[r] && l <= r - 1) {
                    charCount[s[l]] -= 1;
                    l++;
                } 
                charCount[s[l]] -= 1;
				l++;
			}
		}
		return max;
	}
};
// @lc code=end

