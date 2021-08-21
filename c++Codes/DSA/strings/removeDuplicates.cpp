#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;

string removeDups(string S){
    unordered_map<char, int> m;
    string newS;
    for(auto &ch : S){
        if(m.find(ch) == m.end()){
            newS = newS + ch;
            m[ch] = 1;
        }
    }
    return newS;
}