/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        int up = 0, left = 0, right = cols - 1, bottom = rows - 1;
        vector<int> ans;
        while(ans.size() < rows * cols) {
            for(int i = left; i <= right; i++) {
                ans.push_back(matrix[up][i]);
            }
            up++;
            for(int i = up; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--;
            for(int i = right; i >= left; i--) {
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
            for(int i = bottom; i >= up; i--) {
                ans.push_back(matrix[left][i]);
            }
            left++;
        }
        return ans;
    }
};
// @lc code=end

