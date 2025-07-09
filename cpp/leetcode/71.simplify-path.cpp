/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> pathTokens;
        int n = path.size();
        string s = "";
        for (int i = 0; i < n; i++) {
            if (path[i] == '/') {
                if(s !=  "") {
                    pathTokens.push_back(s);
                    s = "";
                }
            } else {
                s += path[i];
            }
        }
        if (s != "")
            pathTokens.push_back(s);
            
        stack<string> st;
        for (auto c : pathTokens) {
            if (c == ".")
                continue;
            else if (c == "..") {
                if (!st.empty())
                    st.pop();
                else
                    continue;
            } else 
                st.push(c);
        }
        string ans = "";
        while (!st.empty()) {
            ans = "/" + st.top() + ans;
            st.pop();
        }
        return ans == "" ? "/" : ans;
    }
};
// @lc code=end

