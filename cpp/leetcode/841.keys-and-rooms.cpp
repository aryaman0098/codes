/*
 * @lc app=leetcode id=841 lang=cpp
 *
 * [841] Keys and Rooms
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> visited(rooms.size(), false);
        queue<int> q;
        q.push(0);
        while(!q.empty()) {
            int room = q.front();
            q.pop();
            if(visited[room]) {
                continue;
            } else {
                for(auto c: rooms[room]) {
                    q.push(c);
                }
                visited[room] = true;
            }
        }
        for(auto c: visited) {
            if(!c) return false;
        }
        return true;
    }
};
// @lc code=end

