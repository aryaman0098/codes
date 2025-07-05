/*
 * @lc app=leetcode id=500 lang=cpp
 *
 * [500] Keyboard Row
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string s1 = "qwertyuiop", s2 = "asdfghjkl", s3 = "zxcvbnm";
        vector<char> v(26);
        for (auto c : s1)
            v[c - 'a'] = 't';
        for (auto c : s2)
            v[c - 'a'] = 'm';
        for (auto c : s3)
            v[c - 'a'] = 'd';
        vector<string> ans;
        for (string s : words) {
            bool isValid = true;
            int firstWordIndex = (s[0] - 'a' >= 0) ? s[0] - 'a' : s[0] - 'A';
            char line = v[firstWordIndex];
            for (int i = 1; i < s.length(); i++) {
                int index = (s[i] - 'a' >= 0) ? s[i] - 'a' : s[i] - 'A';
                if (v[index] != line) {
                    isValid = false;
                    break;
                }
            }
            if(isValid) 
                ans.push_back(s);
        }
        return ans;
    }
};
// @lc code=end

