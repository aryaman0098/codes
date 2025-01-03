/*
 * @lc app=leetcode id=2660 lang=cpp
 *
 * [2660] Determine the Winner of a Bowling Game
 */

#include<bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int score1 = 0, score2 = 0;
        for(int i = 0; i < player1.size(); i++) {
            int points1 = player1[i], points2 = player2[i];
            if(
                (i > 0 && player1[i - 1] == 10) || 
                (i > 1 && player1[i - 2] == 10)
            ) points1 *= 2;
            if( 
                (i > 0 && player2[i - 1] == 10) || 
                (i > 1 && player2[i - 2] == 10)
            ) points2 *= 2;
            score1 += points1;
            score2 += points2;
        }
        if(score1 > score2) return 1;
        else if(score2 > score1) return 2;
        else return 0; 
    }
};
// @lc code=end

