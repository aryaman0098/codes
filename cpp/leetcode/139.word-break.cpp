/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> u;
        unordered_map<int, bool> m;
        int n = s.length();
        for (string c : wordDict)
            u.insert(c);
        function<bool(int, int)> isPossible = [&](int startIndex,
                                                  int endIndex) {
            if (endIndex == n)
                return u.find(s.substr(startIndex)) != u.end();
            if (m.find(startIndex) != m.end())
                return m[startIndex];
            string subS = s.substr(startIndex, endIndex - startIndex);
            bool ans;
            if (u.find(subS) != u.end()) {
                ans = isPossible(startIndex, endIndex + 1) ||
                      isPossible(endIndex, endIndex);
            } else {
                ans = isPossible(startIndex, endIndex + 1);
            }
            m[startIndex] = ans;
            return m[startIndex];
        };
        return isPossible(0, 0);
    }
};
// @lc code=end

