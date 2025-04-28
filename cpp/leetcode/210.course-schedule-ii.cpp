/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjL(numCourses, vector<int>{});
        for(auto c: prerequisites) {
            adjL[c[1]].push_back(c[0]);
        }
        vector<int> inDegree(numCourses, 0);
        for(int i = 0; i < numCourses; i++) {
            for(auto c: adjL[i]) {
                inDegree[c]++;
            }
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(inDegree[i] == 0) {
                q.push(i);
            }
        }
        vector<int> topo;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto c: adjL[node]) {
                inDegree[c]--;
                if(inDegree[c] == 0) {
                    q.push(c);
                }
            }
        }
        return (topo.size() == numCourses) ? topo : vector<int>();
    }
};
// @lc code=end

