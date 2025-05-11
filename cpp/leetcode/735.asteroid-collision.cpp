/*
 * @lc app=leetcode id=735 lang=cpp
 *
 * [735] Asteroid Collision
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        int n = asteroids.size();
        for(int i = 0; i < n; i++) {
            if(asteroids[i] > 0) {
                ans.push_back(asteroids[i]);
            } else {
                bool addToAns = true;
                while(
                    ans.size() > 0 && 
                    ans[ans.size() - 1] > 0
                ) {
                    if(ans[ans.size() - 1] < abs(asteroids[i])) ans.pop_back();
                    else if(ans[ans.size() - 1] == abs(asteroids[i])) {
                        ans.pop_back();
                        addToAns = false;
                        break;
                    } else {
                        addToAns = false;
                        break;
                    }
                } 
                if(
                    addToAns && 
                    (ans.size() == 0 || ans[ans.size() - 1] < 0)
                ) ans.push_back(asteroids[i]);
            }
        }
        return ans;
    }
};
// @lc code=end

