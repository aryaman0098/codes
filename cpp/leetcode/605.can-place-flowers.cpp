/*
 * @lc app=leetcode id=605 lang=cpp
 *
 * [605] Can Place Flowers
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for(int i = 0; i < flowerbed.size(); i++) {
            if(n == 0) return true;
            if(flowerbed[i] == 0) {
                bool left = (i == 0) || flowerbed[i - 1] == 0;
                bool right = (i == flowerbed.size() - 1) || flowerbed[i + 1] == 0;
                if(left && right) {
                    flowerbed[i] = 1;
                    n--;
                }
            }
        }
        return n == 0;
    }
};
// @lc code=end

