/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    unordered_map<int, int> u;
public:
    int numDecodings(string s) {
        int n = s.length();
        function<int(int)> numWays = [&](int index) {
            if(s[index] == '0') return 0;
            if(u.find(index) != u.end()) return u[index];
            if (index == n || index == n - 1)
                return 1;
            int ans = numWays(index + 1);
            if(stoi(s.substr(index, 2)) <= 26) {
                ans += numWays(index + 2);
            }
            u[index] = ans;
            return ans;
        };
        return numWays(0);
    }
};
// @lc code=end

