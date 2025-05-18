/*
 * @lc app=leetcode id=316 lang=cpp
 *
 * [316] Remove Duplicate Letters
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> lastOccurrence;
        int n = s.length();
        for(int i = 0; i < n; i++) lastOccurrence[s[i]] = i;
        unordered_map<char, bool> seen;
        stack<char> st;
        for(int i = 0; i < n; i++) {
            if(seen.find(s[i]) == seen.end() || !seen[s[i]]) {
                while(!st.empty() && st.top() > s[i] && lastOccurrence[st.top()] > i) {
                    seen[st.top()] = false;
                    st.pop();
                }
                st.push(s[i]);
                seen[s[i]] = true;
            }
        }
        string ans = "";
        while(!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};
// @lc code=end

