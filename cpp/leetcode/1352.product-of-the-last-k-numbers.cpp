/*
 * @lc app=leetcode id=1352 lang=cpp
 *
 * [1352] Product of the Last K Numbers
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;  

class ProductOfNumbers {
private:
    vector<int> v;
public:
    ProductOfNumbers() {}
    
    void add(int num) {
        if(num == 0) {
            v = {};
        } else if(v.size() == 0) {
            v.push_back(num);
        } else {
            v.push_back(v[v.size() - 1] * num);
        }
    }
    
    int getProduct(int k) {
        if(v.size() < k) return 0;
        else if(v.size() == k) return v[v.size() - 1];
        else return v[v.size() - 1] / v[v.size() - 1 - k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
// @lc code=end

