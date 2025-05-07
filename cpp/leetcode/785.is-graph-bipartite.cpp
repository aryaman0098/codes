/*
 * @lc app=leetcode id=785 lang=cpp
 *
 * [785] Is Graph Bipartite?
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> v(graph.size(), - 1);
        queue<int> q;
        q.push(0);
        v[0] = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(auto c: graph[node]) {
                if(v[c] == -1) {
                    v[c] = (v[node] == 0) ? 1 : 0;
                }
                if(v[c] == v[node]) {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end

