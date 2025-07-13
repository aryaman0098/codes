/*
 * @lc app=leetcode id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length())
            return false;
        unordered_map<char, char> u1;
        unordered_map<char, bool> u2;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (u1.find(s[i]) == u1.end()) {
                if(u2.find(t[i]) != u2.end()) return false;
                u1[s[i]] = t[i];
                u2[t[i]] = true;
                continue;
            }
            if (u1[s[i]] != t[i])
                return false;
        }
        return true;
    }
};
// @lc code=end

