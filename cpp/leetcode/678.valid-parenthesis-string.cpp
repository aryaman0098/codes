/*
 * @lc app=leetcode id=678 lang=cpp
 *
 * [678] Valid Parenthesis String
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        stack<int> s1, s2;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                s1.push(i);
            } else if (s[i] == '*') {
                s2.push(i);
            } else {
                if (!s1.empty())
                    s1.pop();
                else if (!s2.empty())
                    s2.pop();
                else
                    return false;
            }
        }
        while (!s1.empty()) {
            if (s2.empty() || s1.top() > s2.top())
                return false;
            s1.pop();
            s2.pop();
        }
        return true;
    }
};
// @lc code=end

