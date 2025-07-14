/*
 * @lc app=leetcode id=2337 lang=cpp
 *
 * [2337] Move Pieces to Obtain a String
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canChange(string start, string target) {
        stack<pair<char, int>> s1, s2;
        int n = start.length();
        for (int i = 0; i < n; i++) {
            if (start[i] != '_') {
                s1.push({start[i], i});
            }
            if (target[i] != '_') { 
                s2.push({target[i], i});
            }
        }
        if(s1.size() != s2.size()) return false;
        while (!s1.empty()) {
            pair<char, int> p1 = s1.top();
            s1.pop();
            pair<char, int> p2 = s2.top();
            s2.pop();
            if (p1.first != p2.first)
                return false;
            if (p1.first == 'L' && p1.second < p2.second)
                return false;
            if (p1.first == 'R' && p2.second < p1.second)
                return false;
        }
        return true;
    }
};
// @lc code=end

