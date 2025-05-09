/*
 * @lc app=leetcode id=1405 lang=cpp
 *
 * [1405] Longest Happy String
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        auto cmp = [](pair<char, int> a, pair<char, int> b) {
            return a.second < b.second;
        };
        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(cmp)> pq;
        pq.push({'a', a});
        pq.push({'b', b});
        pq.push({'c', c});
        string s = "";
        while(!pq.empty()) {
            pair<char, int> p = pq.top();
            pq.pop();
            if(
                s == "" || 
                !(s.length() >= 2 && s[s.length() - 2] == p.first && s[s.length() - 1] == p.first)
            ) {
                if(p.second >= 2) {
                    s += p.first;
                    s += p.first;
                } else {
                    s += p.first;
                }
                p.second -= 2;
                if(p.second > 0) pq.push(p);
            } else {
                if(pq.empty()) return s;
                pair<char, int> p1 = pq.top();
                pq.pop();
                s += p1.first;
                p1.second -= 1;
                if(p1.second > 0) pq.push(p1);
                if(p.second >= 2) {
                    s += p.first;
                    s += p.first;
                } else {
                    s += p.first;
                }
                p.second -= 2;
                if(p.second > 0) pq.push(p);
            } 
        }
        return s;
    }
};
// @lc code=end

