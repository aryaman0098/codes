/*
 * @lc app=leetcode id=904 lang=cpp
 *
 * [904] Fruit Into Baskets
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> u;
        int l = 0, r = 0, count = 0, maxCount = INT_MIN, n = fruits.size();
        while (r < n) {
            u[fruits[r]]++;
            count++;
            while (u.size() > 2) {
                u[fruits[l]]--;
                if (u[fruits[l]] == 0)
                    u.erase(fruits[l]);
                l++;
                count--;
            }
            r++;
            maxCount = max(maxCount, count);
        }
        return maxCount;
    }
};
// @lc code=end

