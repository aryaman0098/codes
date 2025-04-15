/*
 * @lc app=leetcode id=767 lang=cpp
 *
 * [767] Reorganize String
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> u;
        int maxFreq = 0;
        for(auto c: s) {
            if(u.find(c) == u.end()) u[c] = 0;
            u[c]++;
            if(u[c] > maxFreq) {
                maxFreq = u[c];
            }
        }
        if(maxFreq > ceil((s.length() * 1.0) / 2.0)) return "";
        auto cmp = [](pair<char, int> a, pair<char, int>b) {
            if(a.second == b.second) return a.first > b.first;
            return a.second < b.second;
        };
        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(cmp)> pq;
        for(auto c: u) {
            pq.push({c.first, c.second});
        }
        string ans = "";
        while(!pq.empty()) {
            pair<char, int> mostFreq = pq.top();
            pq.pop();
            if(ans == "" || ans[ans.length() - 1] != mostFreq.first) {
                ans += mostFreq.first;
                mostFreq.second -= 1;
                if(mostFreq.second > 0) pq.push(mostFreq);
            } else {
                pair<char, int> secondMostFreq = pq.top();
                pq.pop();
                ans += secondMostFreq.first;
                ans +=  mostFreq.first;
                secondMostFreq.second -= 1;
                mostFreq.second -= 1;
                if(mostFreq.second > 0) pq.push(mostFreq);
                if(secondMostFreq.second > 0) pq.push(secondMostFreq);
            }
        }
        return ans;
    }
};
// @lc code=end

