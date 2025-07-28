/*
 * @lc app=leetcode id=1899 lang=cpp
 *
 * [1899] Merge Triplets to Form Target Triplet
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool firsValFound = false, secondValFound = false,
             thridValFound = false;
        for (auto c : triplets) {
          if(c[0] <= target[0] && c[1] <= target[1] && c[2] <= target[2]) {
            if(c[0] == target[0]) firsValFound = true;
            if(c[1] == target[1]) secondValFound = true;
            if(c[2] == target[2]) thridValFound = true;
          }
        }
        if (!(firsValFound && secondValFound && thridValFound))
            return false;
        return true;
    }
};
// @lc code=end

