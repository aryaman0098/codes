#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        function<char(char, int)> shiftChar = [](char letter, int shift) {
            return (letter - shift + 26) % 26 + 'a';
        };
        function<string(string)> shiftString = [shiftChar](string s) {
            int shift = s[0];
            string shiftedString = "";
            for (char c : s)
                shiftedString += shiftChar(c, shift);
            return shiftedString;
        };

        unordered_map<string, vector<string>> u;
        for (auto c : strings) {
            string shiftedString = shiftString(c);
            u[shiftedString].push_back(c);
        }
        vector<vector<string>> ans;
        for (auto c : u)
            ans.push_back(c.second);
        return ans;
    }
};