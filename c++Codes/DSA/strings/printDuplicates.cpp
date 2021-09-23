//https://www.geeksforgeeks.org/print-all-the-duplicates-in-the-input-string/

#include<bits/stdc++.h>

using namespace std;

void printDups(string s){
    unordered_map<char, int> m;
    for(auto &ch : s){
        m[ch]++;
    }
    for(auto i = m.begin(); i != m.end(); i++){
        if(i->second > 1){
            cout<<i->first<<" "<<i->second<<endl;
        }
    }
}

int main(){

    string s = "test string";
    printDups(s);
    return 0;
}
