/*
 * @lc app=leetcode id=860 lang=cpp
 *
 * [860] Lemonade Change
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int, int> u;
        u[5] = 0;
        u[10] = 0;
        u[20] = 0;
        for(auto c: bills) {
            if(c == 5) u[c]++;
            else if(c == 10) {
                if(u[5] > 0) {
                    u[5]--;
                    u[10]++;
                } else {
                    return false;
                }

            } else {
                if(u[10] >= 1 && u[5] >= 1) {
                    u[10]--;
                    u[5]--;
                    u[20]++;
                } else if(u[5] >= 3) {
                    u[5] -= 3;
                    u[20]++;
                } else {
                    return false;
                }
            }
        }
        return true; 
    }
};
// @lc code=end
