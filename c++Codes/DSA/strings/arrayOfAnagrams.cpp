#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;

vector<vector<string> > Anagrams(vector<string>& string_list){
    unordered_map<string, vector<string>> m;
    string s;
    for(int i = 0; i < string_list.size(); i++){
        s = string_list[i];
        sort(s.begin(), s.end());
        m[s].push_back(string_list[i]);
    }
    vector<vector<string> > ans;
    for(auto i : m){
        ans.push_back(i.second);
    }
    return ans;
}

int main(){

    return 0;
}
