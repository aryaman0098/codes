/*
 * @lc app=leetcode id=2013 lang=cpp
 *
 * [2013] Detect Squares
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class DetectSquares {
private:
    unordered_map<uint64_t, int> pointCount;
    vector<vector<int>> points;
    uint64_t encode(int a, int b) {
        return (uint64_t((uint32_t)a) << 32) | (uint32_t)b;
    }

public:
    DetectSquares() {}

    void add(vector<int> point) {
        pointCount[encode(point[0], point[1])]++;
        points.push_back({point[0], point[1]});
    }

    int count(vector<int> point) {
        int px = point[0], py = point[1];
        int ans = 0;
        for (auto c : points) {
            int x = c[0], y = c[1];
            if (abs(x - px) != abs(y - py) || x == px || y == py) {
                continue;
            }
            ans += pointCount[encode(x, py)] * pointCount[encode(px, y)];
        }
        return ans;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
// @lc code=end

