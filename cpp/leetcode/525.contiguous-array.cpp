/*
 * @lc app=leetcode id=525 lang=cpp
 *
 * [525] Contiguous Array
 */

#include<bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> u;
        int count = 0, maxLength = 0;
        for(int i = 0; i < nums.size(); i++) {
            count += (nums[i] == 1) ? 1 : -1;            
            if(count == 0) {
                maxLength = max(maxLength, i + 1);
            } else if(u.find(count) != u.end()) {
                maxLength = max(maxLength, i - u[count]);
            } else {
                u[count] = i;
            }
        }
        return maxLength;
    }
};
// @lc code=end

