//https://leetcode.com/problems/longest-common-prefix/submissions/

#include<bits/stdc++.h>

using namespace std;

string longestCommomPrefix(vector<string>& s){
    string lcp = "";
    for(int i = 0; i < s[0].length(); i++){
        for(int j = 1; j < s.size(); j++){
            if(s[j][i] != s[0][i]){
                return lcp;
            }
        }
        lcp += s[0][i];
    }
    return lcp;
}
