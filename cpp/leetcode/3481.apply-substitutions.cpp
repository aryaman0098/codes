/*
 * @lc app=leetcode id=3481 lang=cpp
 *
 * [3481] Apply Substitutions
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string applySubstitutions(vector<vector<string>>& replacements, string text) {
        unordered_map<string, string> u;
        for(auto c: replacements) u[c[0]] = c[1];

        function<bool(string)> areVariablesPresent = [](string s) {
            int n = s.length();
            for (int i = 0; i < n; i++) {
                if (s[i] == '%' && i + 2 < n && s[i + 2] == '%') {
                    return true;
                }
            }
            return false;
        };

        function<string(string)> resolve = [&](string s) {
            if (!areVariablesPresent(s)) {
                return s;
            } else {
                string ans = "";
                int n = s.length();
                for (int i = 0; i < n; i++) {
                    if (s[i] == '%' && i + 2 < n && s[i + 2] == '%') {
                        string var(1, s[i + 1]); 
                        ans += resolve(var);
                        i += 2;
                    } else {
                        ans += s[i];
                    }
                }
                return ans;
            }
        };
        return resolve(text);
    }
};
// @lc code=end

