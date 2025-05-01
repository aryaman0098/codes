/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class MedianFinder {
private: 
    priority_queue<int, vector<int>> l;
    priority_queue<int, vector<int>, greater<int>> h;

    void rebalance() {
        h.push(l.top());
        l.pop();
        if(l.size() < h.size()) {
            l.push(h.top());
            h.pop();
        }
    };

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        l.push(num);
        rebalance();
    }
    
    double findMedian() {
        return (l.size() > h.size()) ? l.top() : (l.top() + h.top()) / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

