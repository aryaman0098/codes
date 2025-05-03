/*
 * @lc app=leetcode id=380 lang=cpp
 *
 * [380] Insert Delete GetRandom O(1)
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class RandomizedSet {
private:
    unordered_map<int, int> u;
    vector<int> v;
public:
    RandomizedSet() {}
    
    bool insert(int val) {
        if(u.find(val) == u.end()) {
            v.push_back(val);
            u[val] = v.size() - 1;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        int index = u[val];
        v[index] = v[v.size() - 1];
        u[v[v.size() - 1]] = index;
        u.erase(val);
        v.pop_back();
    }
    
    int getRandom() {
        int index = (rand() / RAND_MAX) * (v.size() - 1);
        return v[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end

