//https://leetcode.com/problems/permutation-in-string/

#include<bits/stdc++.h>

using namespace std;

bool check(unordered_map<char, int> u1, unordered_map<char, int> u2){
    for(auto m : u2){
        if(u1[m.first] != m.second)
            return false;
    }
    return true;
}

bool checkInclusion(string s1, string s2) {
    unordered_map<char, int> u1, u2;
    for(int i = 0; i < s1.length(); i++){
        u1[s1[i]]++;
    }
    int l = 0;    
    for(int i = 0; i < s2.length(); i++){
        u2[s2[i]]++;
        if(i >= s1.length() - 1){
            if(check(u1, u2))
                return true;
            u2[s2[l]]--;
            if(u2[s2[l]] == 0)
                u2.erase(s2[l]);
            l++;
        }
    }
    return false;
}

int main(){
    cout<<checkInclusion("abb", "eidbaooo");
    return 0;
}
