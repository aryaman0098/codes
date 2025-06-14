/*
 * @lc app=leetcode id=1046 lang=cpp
 *
 * [1046] Last Stone Weight
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>> pq;
        for (auto c : stones)
            pq.push(c);
        while (!pq.empty() && pq.size() != 1) {
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();
            if (y > x)
                pq.push(y - x);
        }
        return pq.size() == 1 ? pq.top() : 0;
    }
};
// @lc code=end

