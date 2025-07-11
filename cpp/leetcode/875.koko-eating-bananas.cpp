/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());
        while (l < r) {
            int mid = (r + l) / 2;
            int time = 0;
            for (auto c : piles) {
                time += ceil((c * 1.0) / mid);
            }
            if (time <= h)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};
// @lc code=end

