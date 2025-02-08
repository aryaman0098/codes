/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

#include<bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        string updatedS = "";
        for(char c: s) {
            if(
                ((int)c >= 48 && (int)c <= 57) ||
                ((int)c >= 65 && (int)c <= 90) ||
                ((int)c >= 97 && (int)c <= 122)
            ) {
                if((int)c >= 65 && (int)c <= 90) {
                    updatedS += (char)((int)c + 32);
                } else {
                    updatedS += c;
                }
            }
        }
        int l = 0, r = updatedS.length() - 1;
        while(l < r) {
            if(updatedS[l] != updatedS[r]) return false;
        }
        return true;
    }
};
// @lc code=end

