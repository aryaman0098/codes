/*
 * @lc app=leetcode id=1160 lang=cpp
 *
 * [1160] Find Words That Can Be Formed by Characters
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> v1(26, 0), v2(26, 0);
        for (auto c : chars)
            v1[c - 'a']++;
        int ans = 0;
        for (string s : words) {
            bool canBeMade = true;
            for (char c : s) {
                v2[c - 'a']++;
                if (v2[c - 'a'] > v1[c - 'a']) {
                    canBeMade = false;
                    break;
                }
            }
            ans += canBeMade ? s.length() : 0;
            for(int i = 0; i < 26; i++) v2[i] = 0;
        }
        return ans;
    }
};
// @lc code=end

