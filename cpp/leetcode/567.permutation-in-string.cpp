/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l1 = s1.length(), l2 = s2.length();
        if(l1 > l2) return false;
        unordered_map<char, int> u;
        for(auto c: s1) u[c]++;
        unordered_map<char, int> u2;
        for(int i = 0; i < l1; i++) u2[s2[i]]++;
        for(int i = 0; i <= l2 - l1; i++) {
            bool found = true;
            for(auto c: u) {
                if(u2.find(c.first) == u2.end() || u[c.first] != u2[c.first]) {
                    found = false;
                    break;
                }
            }
            if(found) return true;
            u2[s2[i]]--;
            u2[s2[i + l1]]++;
        }    
        return false;
    }
};
// @lc code=end

