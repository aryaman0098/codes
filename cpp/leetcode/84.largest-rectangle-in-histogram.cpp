/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
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
};
// @lc code=end

