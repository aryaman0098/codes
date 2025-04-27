/*
 * @lc app=leetcode id=733 lang=cpp
 *
 * [733] Flood Fill
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color) return image;
        int row = image.size(), col = image[0].size();
        int startingPixelColor = image[sr][sc];
        queue<pair<int, int>> q;
        q.push({sr, sc});
        vector<pair<int, int>> d = {{-1, 0}, {0, - 1}, {1, 0}, {0, 1}};
        while(!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            image[p.first][p.second] = color;
            for(auto c: d) {
                int newR = p.first + c.first;
                int newC = p.second + c.second;
                if(
                    newR < row && newR >= 0 && 
                    newC < col && newC >= 0 && 
                    image[newR][newC] == startingPixelColor
                ) {
                    q.push({newR, newC});
                }
            }
        }
        return image;   
    }
};
// @lc code=end

