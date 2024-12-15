/*
 * @lc app=leetcode id=1975 lang=cpp
 *
 * [1975] Maximum Matrix Sum
 */

#include<bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int minAbs = INT_MAX;
        int numberOfNegs = 0;
        for(auto r: matrix) {
          for(auto c: r) {
            sum += abs(c);
            if(c < 0) numberOfNegs++;
            minAbs = min(minAbs, abs(c));
          }
        }
        if(numberOfNegs % 2 == 0) return sum;
        else return sum - 2 * minAbs;
    }
};
// @lc code=end

