#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    void backtrack(vector<string> &ans, string container, string s, unordered_map<char, int> newCount) {
        if(container.length() == s.length()) {
            ans.push_back(container);
            return;
        }
        for(auto c: newCount) {
            if(c.second == 0) continue;
            container += c.first;
            newCount[c.first]--;
            backtrack(ans, container, s, newCount);
            container.pop_back();
            newCount[c.first]++;
        }
    }
public:
    vector<string> generatePalindromes(string s) {
        unordered_map<char, int> u;
        for(char c: s) {
            if(u.find(c) == u.end()) u[c] = 0;
            u[c]++;
        }
        int numOdds = 0;
        for(auto c: u) {
            if(c.second % 2 != 0) numOdds++;
            if(numOdds > 1) return {};
        }
        string newS = "";
        string oddNumChar = "";
        unordered_map<char, int> newCount;
        for(auto c: u) {
            if(c.second % 2 != 0) {
                oddNumChar = c.first;
                c.second -= 1;
            }
            for(int i = 0; i < c.second / 2; i++) {
                newS += c.first;
            }
            newCount[c.first] = c.second / 2;
        }
        vector<string> ans;
        backtrack(ans, "", newS, newCount);
        string temp = "";
        for(int i = 0; i < ans.size(); i++) {
            string x = ans[i];
            reverse(x.begin(), x.end());
            ans[i] = ans[i] + oddNumChar + x;
        }
        return ans;
    }
};