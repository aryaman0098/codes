/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size(), r = n - 1, l = 0;
        while(l <= r) {
            while(l < n && nums[l] != val) l++;
            while(r >=0 && nums[r] == val) r--;
            if(l <= r) {
                swap(nums[l], nums[r]);
            }
        }
        cout<<l<<endl;
        return l;
    }
};
// @lc code=end

