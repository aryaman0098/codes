// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation

#include<bits/stdc++.h>

using namespace std;

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



class Solution {
private:
    int maxDepth;
    
    int getMaxDepth(vector<NestedInteger> nestedList, int currDepth) {
        int ans = 0;
        for(NestedInteger c: nestedList) {
            if(c.isInteger()) ans = max(ans, currDepth);
            else ans = max(ans, getMaxDepth(c.getList(), currDepth + 1));
        }
        return ans;
    }

    int getWeightMultipliedSum(vector<NestedInteger> nestedList, int currDepth) {
        int sum = 0;
        for(auto c: nestedList) {
            if(c.isInteger()) sum += (maxDepth - currDepth + 1) * c.getInteger();
            else sum += getWeightMultipliedSum(c.getList(), currDepth + 1);
        }
        return sum;
    }
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        maxDepth = getMaxDepth(nestedList, 1);
        return getWeightMultipliedSum(nestedList, 1);
    }
};