#include<bits/stdc++.h>

using namespace std;

int main(){
    string s = "scpcyxprxxsjyjrww";
    cout<<s.length()<<endl;
    unordered_map<char, int> u;
    for(int i = 0; i < s.length(); i++)
        u[s[i]]++;
    for(auto m : u)
        cout<<m.first<<" "<<m.second<<endl;
}
