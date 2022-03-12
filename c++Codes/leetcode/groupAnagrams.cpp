//https://leetcode.com/problems/group-anagrams/

#include<bits/stdc++.h>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> u;
    string s;
    for(auto m : strs){
        s = m;
        sort(s.begin(), s.end());
        u[s].push_back(m);
    }
    vector<vector<string>> ans;
    for(auto m : u)
        ans.push_back(m.second);
    return ans;
}

int main(){

    return 0;
}


