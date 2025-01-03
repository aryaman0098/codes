/*
 * @lc app=leetcode id=408 lang=cpp
 *
 * [408] Valid Word Abbreviation
 */

#include<bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int parentWordIndexCounter = 0;
        for(int i = 0; i < abbr.length(); i++) {
            string num = "";
            while(
                (int) abbr[i] >= 48 &&
                (int) abbr[i] <= 57
            ) {
                num += abbr[i];
                i++;
            }
            i--;
            if(num != "") {
                if(stoi(num) <= word.length() - parentWordIndexCounter) {
                    parentWordIndexCounter += stoi(num);
                } else {
                    return false;
                }
            } else {    
                if(word[parentWordIndexCounter] != abbr[i]) {
                    return false;
                }
            }
        }
        return true;
    } 
};
// @lc code=end

