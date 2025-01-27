/*
 * @lc app=leetcode id=1306 lang=cpp
 *
 * [1306] Jump Game III
 */

#include<bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(start);
        while(!q.empty()) {
            int i = q.front();
            q.pop();
            if(!visited[i]) {
                visited[i] = true;
                if(arr[i] == 0) return true;
                if(n > i + arr[i]) {
                    q.push(i + arr[i]);
                }
                if(0 <= i - arr[i]) {
                    q.push(i - arr[i]);
                }
            }
        }
        return false;
    }
};
// @lc code=end

