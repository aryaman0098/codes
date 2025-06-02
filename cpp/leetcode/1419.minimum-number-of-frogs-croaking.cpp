/*
 * @lc app=leetcode id=1419 lang=cpp
 *
 * [1419] Minimum Number of Frogs Croaking
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int frogs = 0, maxFrogs = 0;
        unordered_map<char, int> u;
        u['c'] = 0;
        u['r'] = 0;
        u['o'] = 0;         
        u['a'] = 0;
        u['k'] = 0;
        unordered_map<char, char> prev;
        prev['r'] = 'c';
        prev['o'] = 'r';         
        prev['a'] = 'o';
        prev['k'] = 'a';
        for(auto c: croakOfFrogs) {
            u[c]++;
            if(c == 'c') {
                frogs++;
                maxFrogs = max(maxFrogs, frogs);
            } else if(--u[prev[c]] < 0) {
                return - 1;
            }
            if(c == 'k') frogs--;
        }
        return (frogs == 0) ? maxFrogs : -1;  
    }
};
// @lc code=end

