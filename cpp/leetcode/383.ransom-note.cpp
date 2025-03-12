/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 */

#include<bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> ur, um;
        for(auto c: ransomNote) {
            if(ur.find(c) == ur.end()) ur[c] = 1;
            ur[c] += 1;
        }
        for(auto c: magazine) {
            if(um.find(c) == um.end()) um[c] = 1;
            um[c] += 1;
        }
        for(auto c: ransomNote) {
            if(um.find(c) == um.end() || um[c] < ur[c]) return false;
        }
        return true;
    }
};
// @lc code=end

