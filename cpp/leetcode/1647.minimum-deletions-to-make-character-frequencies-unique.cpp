/*
 * @lc app=leetcode id=1647 lang=cpp
 *
 * [1647] Minimum Deletions to Make Character Frequencies Unique
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26, 0);
        for (char c : s)
            freq[c - 97]++;
        sort(freq.begin(), freq.end());
        unordered_set<int> uniqueFreq;
        int count = 0;
        for (auto c : freq) {
            while (c > 0 && uniqueFreq.find(c) != uniqueFreq.end()) {
                c--;
                count++;
            }
            if (c > 0 && uniqueFreq.find(c) == uniqueFreq.end())
                uniqueFreq.insert(c);
        }
        return count;
    }
};
// @lc code=end

