//problem -> https://leetcode.com/problems/longest-substring-without-repeating-characters/submissions/

#include<bits/stdc++.h>

using namespace std;

int lengthOfLongestSubstring(string s){
    if (s.length() == 1){
        return 1;
    }
    vector<int> len;
    string sub;
    int i = 0;
    int j;
    while(i < s.length() -1){
        sub = "";
        for(j = i; j < s.length(); j++){
            if (sub.find(s.substr(j,1)) < 0 || sub.find(s.substr(j,1)) >= s.length()){
                sub = sub + s.substr(j, 1);
            }else{
                len.push_back(j - i);
                i++;
                break;
            }
        }
        if(j == s.length()){
            len.push_back(j - i);
            break;
        }
    }
    return *max_element(len.begin(), len.end());
}
