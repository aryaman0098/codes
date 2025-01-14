/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

#include<bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
private:
public:
    bool dfs(int node, unordered_map<int, vector<int>>& adj, vector<bool>& visited, vector<bool>& inPath) {
        visited[node] = true;
        inPath[node] = true;
        for (auto c : adj[node]) {
            if(!visited[c]) {
                if (dfs(c, adj, visited, inPath)) {
                    return true;
                }
            } else {
                if(inPath[c]) {
                    return true;
                }
            }
        }
        inPath[node] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<bool> visited(numCourses);
        vector<bool> inPath(numCourses);
        for (auto c : prerequisites) {
            if(adj.find(c[1]) == adj.end()) adj[c[1]] = {};
            adj[c[1]].push_back(c[0]);
        }
        for (int i = 0; i < numCourses; i++) {
            if (dfs(i, adj, visited, inPath)) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

