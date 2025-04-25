/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(), col = 0;
        while(row >= 0 && col < matrix[0].size()) {
            if(target < matrix[row][col]) row--;
            else if(target > matrix[row][col]) col++;
            else return true;
        }
        return false;
    }
};
// @lc code=end

