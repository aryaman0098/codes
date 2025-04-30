/*
 * @lc app=leetcode id=85 lang=cpp
 *
 * [85] Maximal Rectangle
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
private: 
    int maximumAreaHistogram(vector<int> heights) {
        int n = heights.size();
        vector<int> l(n), r(n);
        stack<int> s;
        for(int i = 0; i < n; i++) {
            while(!s.empty() && heights[s.top()] >= heights[i]) s.pop();
            if(s.empty()) l[i] = (0);
            else l[i] = (s.top() + 1);
            s.push(i);
        }
        while(!s.empty()) s.pop();
        for(int i = n - 1; i >= 0; i--) {
            while(!s.empty() && heights[s.top()] >= heights[i]) s.pop();
            if(s.empty()) r[i] = (n - 1);
            else r[i] = s.top() - 1;
            s.push(i);
        }
        int maxArea = 0;
        for(int i = 0; i < n; i++) {
            maxArea = max(heights[i] * (r[i] - l[i] + 1), maxArea);
        }
        return maxArea;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxArea = 0, rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> transformedMatrix(rows, vector<int>(cols));
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(i > 0) {
                    if(matrix[i][j] == '0') {
                        transformedMatrix[i][j] = 0;
                    } else {
                        transformedMatrix[i][j] = transformedMatrix[i - 1][j] + 1;
                    }
                } else {
                    transformedMatrix[i][j] = matrix[i][j] - '0';
                }
            }
        }
        for(int i = 0; i < rows; i++) {
            maxArea = max(maxArea, this->maximumAreaHistogram(transformedMatrix[i]));
        }
        return maxArea;
    }
};
// @lc code=end

