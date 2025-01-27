/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

#include<bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        int count = 0, pos = INT_MIN, n = nums.size();
        if(n == 1) return 0;
        for(int i = 0; i < n;) {
            pos = i + nums[i];
            if(pos + 1 >= n) {
                break;
            }
            int j = i + 1;
            int maxJump = pos;
            int index = i + 1;
            while(j < n && j <= pos) {
                if(nums[j] + j > maxJump) {
                    index = j;
                    maxJump = nums[j] + j;
                }
                j++;
            }
            i = index;
            count++;
        }
        return count + 1;   
    }
};
// @lc code=end

