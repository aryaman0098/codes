/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    int operate(string token, int num1, int num2) {
        if(token == "+") return num1 + num2;
        else if(token == "-") return num1 - num2;
        else if(token == "*") return num1 * num2;
        else return num1 / num2;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> s;
        for(auto c: tokens) {
            if(c == "+" || c == "-" || c == "*" || c == "/") {
                string num2 = s.top();
                s.pop();
                string num1 = s.top();
                s.pop();
                int val = operate(c, stoi(num1), stoi(num2));
                s.push(to_string(val));
            } else {
                s.push(c);
            }
        }
        return stoi(s.top());
    }
};
// @lc code=end

