#include<bits/stdc++.h>

using namespace std;

bool isAnagram(string a, string b){
    if(a.length() != b.length()){
        return false;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for(int i = 0; i < a.length(); i++){
        if(a.substr(i, 1) != b.substr(i, 1)){
            return false;
        }
    }
    return true;
}

int main(){

    string a = "cat";
    string b = "tca";
    cout<<isAnagram(a, b);
    return 0;
}
