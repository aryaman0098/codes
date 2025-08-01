/*
 * @lc app=leetcode id=2423 lang=cpp
 *
 * [2423] Remove Letter To Equalize Frequency
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool equalFrequency(string word) {
        vector<int> v(26, 0);
        for (char c : word)
            v[c - 'a']++;
        for (int i = 0; i < 26; ++i) {
            if (v[i] == 0) continue;
            v[i]--;  
            unordered_set<int> s;
            for (int count : v)
                if (count > 0)
                    s.insert(count);
            if (s.size() == 1)
                return true;
            v[i]++;  
        }

        return false;
    }
};
// @lc code=end

