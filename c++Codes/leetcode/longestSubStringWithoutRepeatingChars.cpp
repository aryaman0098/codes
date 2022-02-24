//https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include<bits/stdc++.h>

using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> u;
    int l = 0, r = 0;
    int max = INT_MIN;
    while(r < s.length()){
        cout<<l<<" "<<r<<endl;
        if(u.find(s[r]) == u.end()){
            u[s[r]] = 1;
            r++;
        }else{
            if(r - l  > max)
                max = r - l;
            while(s[l] != s[r]){
                u.erase(s[l]);
                l++;
            }
            u.erase(s[l]);
            l++;
        } 
    }
    if(max < r - l)
        max = r - l;   
    return max;
}

int main(){
    cout<<lengthOfLongestSubstring("ohomm");
    return 0;
}
