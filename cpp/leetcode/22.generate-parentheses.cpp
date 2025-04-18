/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    void backTrack(vector<string> &ans, string s, int leftCount, int rightCount, int n) {
        if(s.length() == 2*n) {
            ans.push_back(s);
            return;
        }
        if(leftCount < n) {
            return backTrack(ans, s + '(', leftCount + 1, rightCount, n);
        }
        if(rightCount < leftCount) {
            return backTrack(ans, s + ')', leftCount, rightCount + 1, n);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        backTrack(ans, "", 0, 0, n);
        return ans;
    }
};
// @lc code=end

