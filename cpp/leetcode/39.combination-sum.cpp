/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    void fillVectorsWithSum(vector<vector<int>> &ans, vector<int> currArray,vector<int> &candidates, int pos, int target, int sum) {
        if(pos == candidates.size()) return;
        if(sum == target) {
            ans.push_back(currArray);
        } else if(sum > target) {
            return;
        } else {
            fillVectorsWithSum(ans, currArray, candidates, pos + 1, target, sum);
            currArray.push_back(candidates[pos]);
            sum += candidates[pos];
            fillVectorsWithSum(ans, currArray, candidates, pos, target, sum);
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        fillVectorsWithSum(ans, temp, candidates, 0, target, 0);
        return ans;
    }
};
// @lc code=end

