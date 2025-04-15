/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    int rows;
    int cols;
    vector<vector<char>> grid;

    bool canStartFrom(int i, int j, string word, int pos, vector<vector<int>> &visited) {
        if(pos == word.length()) return true;
        if(i < 0 || j < 0 || i == rows || j == cols || grid[i][j] != word[pos] || visited[i][j]) return false;
        visited[i][j] = true;
        bool res =  
            canStartFrom(i + 1, j, word, pos + 1, visited) ||
            canStartFrom(i, j + 1, word, pos + 1, visited) ||
            canStartFrom(i - 1, j, word, pos + 1, visited) ||
            canStartFrom(i, j - 1, word, pos + 1, visited);
        visited[i][j] = false;
        return res;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        this->rows = board.size();
        this->cols = board[0].size();
        this->grid = board;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                vector<vector<int>> visited(rows, vector<int>(cols, false));
                if(canStartFrom(i, j, word, 0, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end

