/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
    private:
        unordered_map<char, string> u = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

        void backtrack(vector<string> &ans, string s, int pos, string digit) {
            if(digit == "") {
                ans.push_back(s);
                return;
            }
            for(char c: u[digit[pos]]) {
                backtrack(ans, s + c, pos + 1, digit.substr(pos + 1));
            }
        }

    public:
        vector<string> letterCombinations(string digits) {
            vector<string> ans;
            backtrack(ans, "", 0, digits);
        }
};
// @lc code=end

