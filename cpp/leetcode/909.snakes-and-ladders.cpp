/*
 * @lc app=leetcode id=909 lang=cpp
 *
 * [909] Snakes and Ladders
 */

#include<bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    pair<int, int> intToPos(int n, int length) {
        int r = n / length;
        int c = n % length;
        if(c == 0) {
            if(r % 2 == 0) return {length - r, c};
            else return { length - 1, length - 1 };
        }
        if(r % 2 == 0) {
            return { length - 1 - r, c };
        } else {
            return { length - 1 - r,  length - c};
        }
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        bool snakeLadderPresent = false;
        for(auto c: board) {
            for(auto d: c) {
                if(d != - 1) {
                    snakeLadderPresent = true;
                    break;
                }
            }
            if(snakeLadderPresent) {
                break;
            }
        }
        if(!snakeLadderPresent) {
            return ceil((n * n) / 6.0); 
        }
        queue<pair<int, int>> q;
        vector<bool> visited(n * n , false);
        q.push({1, 0});
        while(!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            visited[p.first - 1] = true;
            int pos = p.first;
            int steps = p.second;
            for(int i = 1; i <= 6; i++) {
                int newPos = pos + i;
                pair<int, int> gridPos = intToPos(newPos, n);
                if(board[gridPos.first][gridPos.second] != -1) {
                    newPos = board[gridPos.first][gridPos.second];
                }
                if(newPos == n * n) {
                    return steps + 1;
                }
                if(!visited[newPos - 1]) {
                    q.push({ newPos, steps + 1 });
                }
            }
        }
        return -1;
    }
};
// @lc code=end

