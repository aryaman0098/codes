/*
 * @lc app=leetcode id=1011 lang=cpp
 *
 * [1011] Capacity To Ship Packages Within D Days
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    bool isFeasible(vector<int>& weights, int c, int days) {
        int numberOfDays = 1, currWeight = 0;
        for(int weight: weights) {
            currWeight += weight;
            if(currWeight > c) {
                numberOfDays++;
                currWeight = weight;
            }
        }
        return numberOfDays <= days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int maxWeight = 0, totalWeight = 0;
        for(auto c: weights) {
            maxWeight = max(maxWeight, c);
            totalWeight += c;
        }
        int l = maxWeight, r = totalWeight;
        while(l < r) {
            int mid = (l + r) / 2;
            if (isFeasible(weights, mid, days)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};
// @lc code=end

