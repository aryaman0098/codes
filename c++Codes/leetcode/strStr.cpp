//https://leetcode.com/problems/implement-strstr/

#include<bits/stdc++.h>

using namespace std;

int strStr(string haystack, string needle) {
    if(needle == "")
        return 0;
    if(haystack == "")
        return -1;
    int n = haystack.length();
    int m = needle.length();
    string s;
    for(int i = 0; i < n; i++){
        if(i >= m - 1){
            s = haystack.substr(i - m + 1, m);
            if(needle == s){
                return i - m + 1;
            }
        }
    }
    return -1;
}

int main(){

    return 0;
}
