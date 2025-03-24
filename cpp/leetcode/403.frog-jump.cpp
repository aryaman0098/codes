/*
 * @lc app=leetcode id=403 lang=cpp
 *
 * [403] Frog Jump
 */

#include<bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    bool canCross(vector<int>& stones) {
        if(stones[1] != 1) return false;
        unordered_map<int, unordered_set<int>> u;
        for(auto c: stones) {
            u[c] = {};
        }
        u[0] = {0};
        u[1] = {1};
        for(int i = 1; i < stones.size(); i++) {
            int currStone = stones[i];
            for(auto c: u[currStone]) {
                if(c - 1 > 0 && u.find(currStone + c - 1) != u.end()) {
                    u[currStone + c - 1].insert(c - 1);
                }
                if(u.find(currStone + c) != u.end()) {
                    u[currStone + c].insert(c);
                }
                if(u.find(currStone + c + 1) != u.end()) {
                    u[currStone + c + 1].insert(c + 1);
                }
            }
        }
        return (u[stones[stones.size() - 1]].size() > 0) ? true : false;
    }
};
// @lc code=end

