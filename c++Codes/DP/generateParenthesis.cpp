//https://leetcode.com/problems/generate-parentheses/

#include<bits/stdc++.h>

using namespace std;

void backTrack(vector<string> ans, string s, int open, int close, int n){
    if(s.length() == n * 2){
        ans.push_back(s);
    }
    if(open < n){
        backTrack(ans, s + "(", open + 1, close, n);
    }
    if(close < open){
        backTrack(ans, s + ")", open, close + 1, n);
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> ans;
    backTrack(ans, "", 0, 0, n);
    return ans;
}

int main(){
    generateParenthesis(3);
    return 0;
}
