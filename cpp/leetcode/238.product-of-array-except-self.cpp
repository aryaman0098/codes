/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

#include<bits/stdc++.h>

using namespace std;

// @lc code=start

//  Can be optimized by not storing suffix product and using prefix product to store answers.
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int numZeroes = 0;
        vector<int> prefixProduct, suffixProduct, ans;
        prefixProduct.push_back(1);
        suffixProduct.push_back(1);
        int product = 1;
        if(nums[nums.size() - 1] == 0) numZeroes++;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i - 1] == 0) {
                numZeroes++;
            } else {
                product *= nums[i - 1];   
            }
            prefixProduct.push_back(product);
        }
        product = 1;
        for(int i = nums.size() - 2; i >= 0; i--) {
            if(nums[i + 1] != 0) {
                product *= nums[i + 1];   
            }
            suffixProduct.push_back(product);
        }
        if(numZeroes >= 2) {
            for(int i = 0; i < nums.size(); i++) {
                ans.push_back(0);
            }
        } else if(numZeroes == 1) {
            for(int i = 0; i < nums.size(); i++) {
                if(nums[i] == 0) {
                    ans.push_back(prefixProduct[i] * suffixProduct[nums.size() - 1 - i]);
                } else {
                    ans.push_back(0);
                }
            }
        } else {
            for(int i = 0; i < nums.size(); i++) {
                ans.push_back(prefixProduct[i] * suffixProduct[nums.size() - 1 - i]);
            }
        }
        return ans;
    }
};
// @lc code=end

