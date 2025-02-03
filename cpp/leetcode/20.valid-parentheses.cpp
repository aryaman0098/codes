/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

#include<bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto c: s) {
            if(c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                if(st.empty()) return false;
                char topElement = st.top();
                if(!(
                    (c == ')' && topElement == '(') ||
                    (c == '}' && topElement == '{') ||
                    (c == ']' && topElement == '[')
                )) {
                    return false;
                } else {
                    st.pop();
                }
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};
// @lc code=end

