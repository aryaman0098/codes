//https://leetcode.com/problems/count-and-say/

#include<bits/stdc++.h>

using namespace std;

string countAndSay(int n){
    if(n == 1){
        return "1";
    }
    string s = countAndSay(n - 1);
    stack<int> st;
    for(int i = s.length() - 1; i >= 0; i--){
        st.push((int)s[i] - 48);
    }
    string ans = "";
    int currNum, preNum = st.top();
    int count = 0;
    while(!st.empty()){
        currNum = st.top();
        st.pop();
        if(preNum == currNum){
            count++;
        }else{
            ans += to_string(count) + to_string(preNum);
            count = 1;
            preNum = currNum;
        }
    }
    ans += to_string(count) + to_string(preNum);
    return ans;
}

int main(){

    cout<<countAndSay(11);
    return 0;
}
