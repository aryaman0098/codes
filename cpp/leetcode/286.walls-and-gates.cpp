#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int rows = rooms.size(), cols = rooms[0].size();
        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (rooms[i][j] == 0)
                    q.push({{i, j}, 0});
            }
        }
        vector<pair<int, int>> v = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        while (!q.empty()) {
            pair<pair<int, int>, int> n = q.front();
            q.pop();
            int distance = n.second, r = n.first.first, c = n.first.second;
            if(rooms[r][c] >= distance) {
                rooms[r][c] = distance;
                for (auto x : v) {
                    int nr = r + x.first, nc = c + x.second;
                    if (nr >= 0 && nc >= 0 && nr < rows && nc < cols)
                        q.push({{nr, nc}, distance + 1});
                }
            } else continue;
        }
    }
};