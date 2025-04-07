/*
 * @lc app=leetcode id=2077 lang=cpp
 *
 * [2077] Paths in Maze That Lead to Same Room
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int numberOfPaths(int n, vector<vector<int>>& corridors) {
            unordered_map<int, unordered_set<int>> g;
            for(auto c: corridors) {
                if(c[0] < c[1]) {
                    if(g.find(c[0]) == g.end()) g[c[0]] = {};
                    g[c[0]].insert(c[1]);
                } else {
                    if(g.find(c[1]) == g.end()) g[c[1]] = {};
                    g[c[1]].insert(c[0]);
                }
            }
            int ans = 0;
            for(auto c: corridors) {
                for(auto e: g[c[0]]) {
                    if(g[c[1]].find(e) != g[c[1]].end()) ans++;
                }
            }
            return ans;
        }
    };
// @lc code=end

