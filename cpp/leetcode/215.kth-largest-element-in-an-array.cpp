/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i: nums) {
            pq.push(i);
            if(pq.size() > k) {
                pq.pop();
            }
        }
        return pq.top();
    }
};
// @lc code=end

