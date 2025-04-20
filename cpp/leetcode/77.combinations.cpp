/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    void backtrack(
        vector<vector<int>> &ans, 
        vector<int> v, 
        int k, 
        int start, 
        int n
    ) {
        if(v.size() == k) {
            ans.push_back(v);
            return;
        }
        for(int  i = start; i <= n; i++) {
            v.push_back(i);
            backtrack(ans, v, k, i + 1, n);
            v.pop_back();
        }
    }   
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        backtrack(ans, {}, k, 1, n);
        return ans;
    }
};
// @lc code=end

