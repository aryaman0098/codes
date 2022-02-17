//https://leetcode.com/problems/is-subsequence/

#include<bits/stdc++.h>

using namespace std;

bool isSubsequence(string s, string t) {
    int n = s.length();
    int m = t.length();
    int c = 0;
    for(int i = 0; i < m; i++) {
        if(c == m && i < m){
            return true;
        }
        if(s[c] == t[i]){
            c++;
        }
    }
    return false;
}

int main(){

    return 0;
}
