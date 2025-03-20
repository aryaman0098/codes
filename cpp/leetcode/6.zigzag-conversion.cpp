/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] Zigzag Conversion
 */

#include<bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        unordered_map<int, string> u;
        if(numRows == 1) return s;
        for(int i = 0; i < numRows; i++) {
            u[i] = "";
        }
        int counter = 0;
        bool increasingSeq = true;
        for(int i = 0; i < s.length(); i++) {
            u[counter] += s[i];
            
            if(counter == 0) {
                increasingSeq = true;
            }
            if(counter == numRows - 1) {
                increasingSeq = false;
            }

            if(increasingSeq) {
                counter++;
            } else {
                counter--;
            }
        }
        string ans= "";
        for(int i = 0; i < numRows; i++) {
            ans += u[i];
        }
        return ans;
    }
};
// @lc code=end

