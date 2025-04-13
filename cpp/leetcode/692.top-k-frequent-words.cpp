/*
 * @lc app=leetcode id=692 lang=cpp
 *
 * [692] Top K Frequent Words
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> u;
        for(string c: words) {
            if(u.find(c) == u.end()) u[c] = 0;
            u[c] += 1;
        }
        vector<pair<string, int>> wordFreq;
        for(auto c: u) {
            wordFreq.push_back({c.first, c.second});
        }
        auto cmp = [](const pair<string, int>& a, const pair<string, int>& b) {
            if (a.second == b.second) return a.first > b.first; 
            return a.second < b.second;
        };
        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> pq;
        for(auto c: wordFreq) {
            pq.push(c);
        }
        vector<string> ans;
        int count = 0;
        while(count < k) {
            ans.push_back(pq.top().first);
            pq.pop();
            count++;
        }
        return ans;
    }
};
// @lc code=end

