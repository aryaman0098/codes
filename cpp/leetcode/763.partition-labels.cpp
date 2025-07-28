/*
 * @lc app=leetcode id=763 lang=cpp
 *
 * [763] Partition Labels
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> lastOccr;
        int n = s.length();
        for (int i = 0; i < n; i++)
            lastOccr[s[i]] = i;
        vector<int> ans;
        int l = 0, farthestCharInCurrPartition = 0;
        for (int r = 0; r < n; r++) {
            farthestCharInCurrPartition = max(farthestCharInCurrPartition, lastOccr[s[r]]);
            if (r == farthestCharInCurrPartition) {
                ans.push_back(r - l + 1);
                l = r + 1;
            }
        }
        return ans;
    }
};
// @lc code=end

