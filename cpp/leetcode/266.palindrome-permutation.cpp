/*
 * @lc app=leetcode id=266 lang=cpp
 *
 * [266] Palindrome Permutation
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> u;
        for(char c: s) {
            if(u.find(c) == u.end()) u[c] = 0;
            u[c] += 1;
        }
        int numOdds = 0;
        for(auto c: u) {
            if(c.second % 2 != 0) numOdds++;
        }
        return (numOdds == 0 || numOdds == 1) ? true : false;
    }
};
// @lc code=end

