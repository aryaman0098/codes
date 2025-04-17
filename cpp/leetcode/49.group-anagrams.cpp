/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> u;
        for(auto c: strs) {
            string temp = c;
            sort(temp.begin(), temp.end());
            if(u.find(temp) == u.end()) u[temp] = {};
            u[temp].push_back(c);
        }
        vector<vector<string>> ans;
        for(auto c: u) {
            ans.push_back(c.second);
        }
        return ans;
    }
};
// @lc code=end

