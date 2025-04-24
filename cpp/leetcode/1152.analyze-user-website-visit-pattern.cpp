#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        unordered_map<string, vector<pair<string, int>>> u;
        for(int i = 0; i < username.size(); i++) {
            if(u.find(username[i]) == u.end()) u[username[i]] = {};
            u[username[i]].push_back({website[i], timestamp[i]});
        }
        unordered_map<string, int> count;
        for(auto c: u) {
            sort(u[c.first].begin(), u[c.first].end(), [](pair<string, int> a, pair<string, int> b) {
                return a.second < b.second;
            });
            unordered_set<string> seen;
            for(int i = 0; i < u[c.first].size(); i++) {
                for(int j = i + 1; j < u[c.first].size(); j++) {
                    for(int  k = j + 1; k < u[c.first].size(); k++) {
                        string s = u[c.first][i].first + " " + u[c.first][j].first + " " + u[c.first][k].first;
                        if(seen.count(s)) continue;
                        seen.insert(s);
                        count[s]++;
                    }
                }
            }
        }
        string s;
        int maxCount = INT_MIN;
        for(auto c: count) {
            if(c.second > maxCount) {
                maxCount = c.second;
                s = c.first;
            } else if(c.second == maxCount && c.first < s) {
                s = c.first;
            }
        } 
        vector<string> ans;
        string temp = "";
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == ' ') {
                ans.push_back(temp);
                temp = "";
                continue;
            }
            temp += s[i];
        }
        ans.push_back(temp);
        return ans;  
    }
};