
// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
public:
    // Constructor initializes an empty nested list.
    NestedInteger();

    // Constructor initializes a single integer.
    NestedInteger(int value);

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value);

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni);

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    int getWeightMultipliedSum(vector<NestedInteger> nestedList, int weight) {
        int ans = 0;
        for(auto c: nestedList) {
            if(!c.isInteger()) {
                ans += getWeightMultipliedSum(c.getList(), weight + 1);
            } else {
                ans += c.getInteger() * weight;
            }
        }
        return ans;
    }
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        return getWeightMultipliedSum(nestedList, 1);
    }
};