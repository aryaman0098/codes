/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int count = 0, n = s.length();
        for(int i = 0; i < n; i++) {
            count++;
            int l = i - 1, r = i + 1;
            while(
                l >= 0 && 
                r < n &&
                s[l] == s[r]
            ) {
                count++;
                l--;
                r++;
            }
        }
        for(int i = 0; i < n; i++) {
            int l = i, r = i + 1;
            while(
                l >= 0 && 
                r < n &&
                s[l] == s[r]
            ) {
                count++;
                l--;
                r++;
            }
        }        
        return count;
    }
};
// @lc code=end

