/*
 * @lc app=leetcode id=981 lang=cpp
 *
 * [981] Time Based Key-Value Store
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class TimeMap {
private:
    unordered_map<string, vector<pair<string, int>>> u;
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        if(u.find(key) == u.end()) u[key] = {};
        u[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if(u.find(key) == u.end()) return "";;
        auto cmp = [](int t, const pair<string, int>& p) {
            return t < p.second;
        };
        int index = upper_bound(u[key].begin(), u[key].end(), timestamp, cmp) - u[key].begin() - 1;
        if(index < 0) return "";
        return u[key][index].first;
    }
};
    

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
// @lc code=end

