/*
 * @lc app=leetcode id=901 lang=cpp
 *
 * [901] Online Stock Span
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class StockSpanner {
private:
    stack<pair<int, int>> s;
public:
    StockSpanner() {}
    
    int next(int price) {
        int count = 1;
        while(!s.empty() && s.top().first <= price) {
            count += s.top().second;
            s.pop();
        }
        s.push({price, count});
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// @lc code=end

