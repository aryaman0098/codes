/*
 * @lc app=leetcode id=289 lang=cpp
 *
 * [289] Game of Life
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<pair<int, int>> v = {
            {-1, -1},
            {-1, 0},
            {-1, + 1},
            {0, + 1},
            {+1, + 1},
            {+1, 0},
            {+1, - 1},
            {0, - 1}
        };
        int row = board.size(), col = board[0].size();
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                int countLive = 0, countDead = 0;
                for(auto c: v) {
                    int newR = i + c.first, newC = j + c.second;
                    if(newR >= 0 && newC >= 0 && newR < row && newC < col) {
                        if(board[newR][newC] == 0 || board[newR][newC] == -1) {
                            countDead +=1 ;
                        } else if(board[newR][newC] == 1 || board[newR][newC] == -2) {
                            countLive += 1;
                        }
                    } 
                }
                if(board[i][j] == 1) {
                    if(countLive < 2) board[i][j] = -2;
                    if(2 == countLive && countLive == 3) board[i][j] = 1;
                    if(countLive > 3) board[i][j] = -2;
                }
                if(board[i][j] == 0) {
                    if(countLive == 3) board[i][j]= -1;
                }
            }
        }
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(board[i][j] == -2) board[i][j] = 0;
                if(board[i][j] == -1) board[i][j] = 1;
            }
        }
    }
};
// @lc code=end

