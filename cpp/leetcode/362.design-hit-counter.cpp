/*
 * @lc app=leetcode id=362 lang=cpp
 *
 * [362] Design Hit Counter
 */

#include<bits/stdc++.h>

using namespace std;

// @lc code=start
class HitCounter {

private:

    unordered_map<int, int> timestampHitsMap;

    void updateMap(int timestamp) {
        vector<int> timestampsToRemove;
        for(auto c: timestampHitsMap) {
            if(c.first <= timestamp - 300) timestampsToRemove.push_back(c.first);
        }
        for(auto c: timestampsToRemove) timestampHitsMap.erase(c);
    }

public:

    HitCounter() {
        timestampHitsMap = {};
    }
    
    void hit(int timestamp) {
        if(timestamp > 300) {
            updateMap(timestamp);
        }   
        if(timestampHitsMap.find(timestamp) == timestampHitsMap.end()) {
            timestampHitsMap[timestamp] = 1;
        } else {
            timestampHitsMap[timestamp]++;
        }
        return;
    }
    
    int getHits(int timestamp) {
        if(timestamp > 300) {
            updateMap(timestamp);
        }
        int ans = 0;
        for(auto c: timestampHitsMap) {
            ans += c.second;
        }   
        return ans;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */
// @lc code=end

