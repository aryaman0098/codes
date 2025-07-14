/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        string ans = "";
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (97 <= s[i] && s[i] <= 122)
                ans += s[i];
            else {
                int k = i;
                while(48<= s[i] && s[i] <= 57) i++;
                int count = stoi(s.substr(k, i - k));
                string tem = "";
                stack<char> st;
                st.push(s[i]);
                tem +=s[i];
                while(i < n && !st.empty()) {
                  i++;
                  tem += s[i];
                  if(s[i] == '[') st.push(s[i]);
                  if(s[i] == ']') st.pop();
                }
                string decodedString = decodeString(tem.substr(1, tem.length() - 2));
                for (int j = 0; j < count; j++)
                    ans += decodedString;
            }
        }
        return ans;
    }
};
// @lc code=end

