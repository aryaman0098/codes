/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

#include<bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1){
            return true;
        }
        int canReach = nums[0];
        for(int i = 1; i <= canReach; i++){
            canReach = max(i + nums[i], canReach);
            if(canReach >= nums.size() - 1){
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

