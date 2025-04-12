/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> u;
        for(int num: nums) {
            if(u.find(num) == u.end()) u[num] = 0;
            u[num] += 1;
        }
        auto cmp = [](pair<int, int> a, pair<int, int> b) {return a.second < b.second;};
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq;
        for(auto c: u) {
            pq.push({c.first, c.second});
        }
        vector<int> ans;
        int count = 0;
        while(count < k) {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};
// @lc code=end

