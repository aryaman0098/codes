/*
 * @lc app=leetcode id=323 lang=cpp
 *
 * [323] Number of Connected Components in an Undirected Graph
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> am(n, vector<int> {});
        vector<int> visited(n, false);
        for(auto c: edges) {
            am[c[0]].push_back(c[1]);
            am[c[1]].push_back(c[0]);
        }
        int components = 0;
        stack<int> s;
        for(int i = 0; i < n; i++) {
            if(visited[i]) continue;
            s.push(i);
            while(!s.empty()) {
                int currNode = s.top();
                s.pop();
                if(visited[currNode]) continue;
                visited[currNode] = true;
                for(auto c: am[currNode]) {
                    if(!visited[c]) s.push(c);
                }
            }
            components++;
        }
        return components;
    }
};
// @lc code=end

