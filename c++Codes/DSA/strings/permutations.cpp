//https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1

#include<bits/stdc++.h>

using namespace std;

void permute(string s, int l, int r, vector<string>& v){
    if(l == r){
        v.push_back(s);
    }else{
        for(int i = l; i <= r; i++){
            swap(s[l], s[i]);
            permute(s, l + 1, r, v);
            swap(s[l], s[i]);
        }
    }
}

vector<string> find_permutation(string S){
    vector<string> ans;
    int n = S.size();
    permute(S, 0, n - 1, ans);
    sor(ans.begin(), ans.end());
    return ans;
}

int main(){
    
    return 0;
}
