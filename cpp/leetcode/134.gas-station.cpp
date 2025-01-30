/*
 * @lc app=leetcode id=134 lang=cpp
 *
 * [134] Gas Station
 */

#include<bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(), totalGain = 0, currGain = 0, pos = 0;
        for(int i = 0; i < n; i++) {
            totalGain += gas[i] - cost[i];
            currGain += gas[i] - cost[i];
            if(currGain < 0) {
                currGain = 0;
                pos = i + 1;
            }
        }
        return (totalGain >= 0) ? pos : -1;
    }
};
// @lc code=end

