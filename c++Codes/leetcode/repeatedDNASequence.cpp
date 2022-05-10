//https://leetcode.com/problems/repeated-dna-sequences/

#include<bits/stdc++.h>

using namespace std;

vector<string> findRepeatedDnaSequences(string s) {
    if(s.length() < 10)
        return {};
    unordered_map<string, int> u;
    string sub;
    int l = 0;
    vector<string> ans;
    while(l + 9 < s.length()) {
        sub = s.substr(l, 10);
        u[sub]++;
        if(u[sub] == 2)
            ans.push_back(sub);
        l++;
    }
    return ans;
}

int main(){

    return 0;
}
