/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(auto c: nums) s.insert(c);
        int longest = 0, currLength = 0;
        for(auto c: s) {
            if(s.find(c - 1) == s.end()) {
                currLength = 0;
                int val = c;
                while(s.find(val) != s.end()) {
                    val++;
                    currLength++;
                }
            }
            longest = max(longest, currLength);
        }
        return longest;
    }
};
// @lc code=end

