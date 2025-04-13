/*
 * @lc app=leetcode id=1772 lang=cpp
 *
 * [1772] Sort Features by Popularity
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> sortFeatures(vector<string>& features, vector<string>& responses) {
        unordered_map<string, int> u;
        for(int i = 0; i < responses.size(); i++) {
            string temp = "";
            unordered_set<string> s;
            for(char d: responses[i]) {
                if(d == ' ') {
                    s.insert(temp);
                    temp = "";
                } else {
                    temp += d;
                }
            }
            s.insert(temp);
            for(auto c: s) {
                if(u.find(c) == u.end()) u[c] = 0;
                u[c] += 1;
            }
        }
        vector<pair<string, pair<int, int>>> featureResponseCount;
        for(int i = 0; i < features.size(); i++) {
            int count;
            if(u.find(features[i]) == u.end()) count = 0;
            else count = u[features[i]];
            featureResponseCount.push_back({features[i], {count, i}});
        }
        sort(featureResponseCount.begin(), featureResponseCount.end(), [](pair<string, pair<int, int>> a, pair<string, pair<int, int>> b) {
            if(a.second.first == b.second.first) return a.second.second < b.second.second;
            else return a.second.first > b.second.first;
        });
        vector<string> ans;
        for(auto c: featureResponseCount) {
            ans.push_back(c.first);
        }
        return ans;
    }
};
// @lc code=end

