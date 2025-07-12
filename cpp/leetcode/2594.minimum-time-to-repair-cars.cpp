/*
 * @lc app=leetcode id=2594 lang=cpp
 *
 * [2594] Minimum Time to Repair Cars
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        int minRank = INT_MAX, maxRank = INT_MIN, n = ranks.size();
        unordered_map<int, int> freq;
        for (auto rank : ranks) {
            minRank = min(minRank, rank);
            maxRank = max(maxRank, rank);
            freq[rank]++;
        }
        long long l = 1, r = (long long) maxRank * cars * cars;
        while (l < r) {
            long long mid = (l + r) / 2;
            long long numCars = 0;
            for (auto c : freq)
                numCars += c.second * (long long)sqrt(mid / (double)c.first);
            if (numCars >= cars)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};
// @lc code=end

