/*
 * @lc app=leetcode id=2561 lang=cpp
 *
 * [2561] Rearranging Fruits
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> count;
        for (int b : basket1)
            count[b]++;
        for (int b : basket2)
            count[b]--;

        vector<int> swap1, swap2;
        int minElem = INT_MAX;

        for (auto& [val, cnt] : count) {
            if (cnt % 2 != 0)
                return -1;
            int times = abs(cnt) / 2;
            minElem = min(minElem, val);

            if (cnt > 0)
                swap1.insert(swap1.end(), times, val);
            else
                swap2.insert(swap2.end(), times, val);
        }

        sort(swap1.begin(), swap1.end());
        sort(swap2.rbegin(), swap2.rend());

        long long cost = 0;
        for (size_t i = 0; i < swap1.size(); ++i) {
            int a = swap1[i], b = swap2[i];
            cost += min(min(a, b), 2 * minElem);
        }
        return cost;
    }
};
// @lc code=end

