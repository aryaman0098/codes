/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class MinStack {
private:
    stack<int> st, mSt;
public:
    MinStack() {}
    
    void push(int val) {
        st.push(val);
        if(mSt.empty() || val <= mSt.top()) mSt.push(val);
    }
    
    void pop() {
        int val = st.top();
        st.pop();
        if(val == mSt.top()) mSt.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mSt.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

