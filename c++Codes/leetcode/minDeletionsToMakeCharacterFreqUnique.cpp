//https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/

#include<bits/stdc++.h>

using namespace std;

int minDeletions(string s) {
    int a[26];
    for(int i = 0; i < 26; i++)
        a[i] = 0;
    for(auto c : s)
        a[c - 'a']++;
    vector<int> freq;
    for(int i = 0; i < 26; i++){
        if(a[i] > 0)
            freq.push_back(a[i]);
    }
    sort(freq.begin(), freq.end(), greater<int>());
    unordered_set<int> u;
    int counter;
    u.insert(freq[0]);
    for(int i = 1; i < freq.size(); i++){
        while(u.find(freq[i]) != u.end()){
            freq[i]--;
            counter++;
        }
        u.insert(freq[i]);
    } 
    return counter;
}

int main(){

    return 0;
}
