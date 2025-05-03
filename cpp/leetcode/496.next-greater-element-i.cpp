/*
 * @lc app=leetcode id=496 lang=cpp
 *
 * [496] Next Greater Element I
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        stack<int> s;
        unordered_map<int, int> u;
        for(int i = n - 1; i >= 0; i--) {
            while(!s.empty() && s.top() < nums2[i]) 
                s.pop();
            if(s.empty()) 
                u[nums2[i]] = -1;
            else 
                u[nums2[i]] = s.top();
            s.push(nums2[i]);
        }
        vector<int> ans;
        for(auto c: nums1) {
            ans.push_back(u[nums1[c]]);
        }
        return ans;
    }
};
// @lc code=end

